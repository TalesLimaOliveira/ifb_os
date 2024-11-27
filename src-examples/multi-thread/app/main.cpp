#include <chrono>
#include <iostream>
#include <pthread.h>
#include <string>
#include <unordered_set>
#include "crawler.h"
#include "master.h"
#include "utils.h"

#define N_THR 8

int waiting = 0;
int max_search = 1000;
pthread_mutex_t mutex;
pthread_cond_t cond;

std::fstream outfile("pdfs_found.txt");

std::unordered_set<std::string> q_urls;
std::unordered_set<std::string> s_urls_accessed;
std::unordered_set<std::string> s_pdfs;

/**
 * @brief Main function that initializes and starts the web crawler.
 * 
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Exit status.
 */
int main(int argc, char* argv[]){
    // Open the output file for writing found PDFs
    outfile.open("pdfs_found.txt", std::fstream::out);

    // Set the maximum number of URLs to search if provided as an argument
    if (argc > 1){
        max_search = strtod(argv[1], NULL);
    }

    // Record the start time of the scraping process
    auto start = std::chrono::system_clock::now();

    // Create and initialize threads
    pthread_t thr[N_THR];
    const std::string url = "https://www.ifb.edu.br";
    q_urls.insert(url);

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_t prod;

    // Create master and crawler threads
    pthread_create(&prod, NULL, master, (void*)15);
    for (long i = 0; i < N_THR; i++){
        pthread_create(&thr[i], NULL, crawler, (void*)i);
    }
    for (long i = 0; i < N_THR; i++){
        pthread_join(thr[i], NULL);
    }
    pthread_join(prod, NULL);
    pthread_mutex_destroy(&mutex);

    // Record the end time of the scraping process
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    // Display the results of the scraping process
    std::cout << "\nScraping finished in " << std::ctime(&end_time)
              << "elapsed time: " << color_codes[3] << elapsed_seconds.count()
              << default_color << " seconds" << std::endl;
    std::cout << "PDFs found: " << color_codes[2] << s_pdfs.size()
              << default_color << std::endl;
    std::cout << "URLs accessed: " << color_codes[1] << s_urls_accessed.size()
              << default_color << std::endl;

    // Close the output file
    outfile.close();

    return 0;
}
