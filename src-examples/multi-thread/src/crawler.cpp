#include <iostream>
#include <pthread.h>
#include <string>
#include <unordered_set>
#include <vector>
#include "utils.h"
#include "crawler.h"

extern int waiting;
extern int max_search;
extern pthread_mutex_t mutex;
extern pthread_cond_t cond;
extern std::fstream outfile;
extern std::unordered_set<std::string> q_urls;
extern std::unordered_set<std::string> s_urls_accessed;
extern std::unordered_set<std::string> s_pdfs;

/**
 * @brief Crawler thread function that processes URLs and scrapes content.
 * 
 * @param arg Argument passed to the thread.
 * @return void* 
 */
void* crawler(void* arg){
    long thr_id = (long)arg;
    while (true){
        pthread_mutex_lock(&mutex);
        while (q_urls.empty()){
            waiting++;
            pthread_cond_wait(&cond, &mutex);
            waiting--;
            break;
        }

        if (q_urls.empty()){
            pthread_mutex_unlock(&mutex);
            break;
        }

        // Get the next URL to visit
        std::string url_to_visit = *q_urls.begin();
        display_current_date_time();
        std::cout << color_codes[6] << "thr"
                  << "#" << thr_id << color_codes[1] << " accessed "
                  << default_color << url_to_visit << std::endl;

        s_urls_accessed.insert(url_to_visit);
        q_urls.erase(url_to_visit);
        pthread_mutex_unlock(&mutex);

        std::string page = request(url_to_visit);
        std::vector<std::string> out_urls;
        std::unordered_set<std::string> out_pdfs;
        scrape(page, &out_urls, &out_pdfs);

        pthread_mutex_lock(&mutex);
        for (const auto& u : out_urls){
            if (s_urls_accessed.find(u) == s_urls_accessed.end()){
                if ((max_search > 0 && s_urls_accessed.size() + q_urls.size() < max_search) || max_search == -1){
                    q_urls.insert(u);
                }
            }
        }

        if (outfile.is_open()){
            outfile << url_to_visit << std::endl;
            for (const auto& u : out_pdfs){
                outfile << "\t " << u << std::endl;
            }
            outfile << std::endl;
        }

        for (const auto& u : out_pdfs){
            s_pdfs.insert(u);
            display_current_date_time();
            std::cout << color_codes[6] << "thr"
                      << "#" << thr_id << color_codes[2] << " pdf ---> "
                      << default_color << u << std::endl;
        }

        if (!q_urls.empty()){
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}