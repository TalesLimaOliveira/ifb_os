#include <chrono>
#include <ctime>
#include <curl/curl.h>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_set>
#include <vector>
#include <htmlcxx/html/ParserDom.h>
#include "utils.h"

// Default color and color codes for console output
std::string default_color = "\033[1;0m";
std::string color_codes[] = {"\033[1;31m", "\033[1;32m", "\033[1;33m",
                             "\033[1;34m", "\033[1;35m", "\033[0;37m",
                             "\e[1;97m"};

/**
 * @brief Displays the current date and time in a specific color format.
 */
void display_current_date_time(){
    char time_buffer[20];
    std::time_t now = std::time(nullptr);
    tm* ltm = localtime(&now);

    // Format the current time as a string
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", ltm);
    std::cout << color_codes[5] << time_buffer << " ";
}

/**
 * @brief Callback function for handling data received from a CURL request.
 * 
 * @param buffer Pointer to the data received.
 * @param size Size of each data element.
 * @param nmemb Number of data elements.
 * @param user_pointer Pointer to the user data.
 * @return size_t Size of the data processed.
 */
size_t buffer_callback(char* buffer, size_t size, size_t nmemb, void* user_pointer){
    size_t new_size = size * nmemb;
    ((std::string*)user_pointer)->append(buffer, new_size);
    return new_size;
}

/**
 * @brief Makes an HTTP request to the specified URL and returns the response as a string.
 * 
 * @param url The URL to request.
 * @return std::string The response from the server.
 */
std::string request(const std::string& url){
    CURL* curl = curl_easy_init();
    if (!curl){
        std::cerr << "curl_easy_init() failed to initialize libcurl" << std::endl;
        return "";
    }

    std::string page;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, buffer_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &page);

    int res = curl_easy_perform(curl);
    if (res != CURLE_OK){
        std::cerr << "curl_easy_perform() failed: " << res << std::endl;
    }
    curl_easy_cleanup(curl);

    return page;
}

/**
 * @brief Scrapes the HTML content for URLs and PDFs, storing them in the provided containers.
 * 
 * @param html The HTML content to scrape.
 * @param out_urls Pointer to a vector to store found URLs.
 * @param out_pdfs Pointer to an unordered set to store found PDFs.
 */
void scrape(const std::string& html, std::vector<std::string>* out_urls, std::unordered_set<std::string>* out_pdfs){
    const std::regex url_pdf("((https?)://).*(ifb.edu.br).*.pdf");
    const std::regex domain("((https?)://)(www.ifb.edu.br)+([a-zA-Z0-9\\-.,@?^=%&:/~+#]*[a-zA-Z0-9\\-@?^=%&/~+#])?");
    const std::regex subpath("/([-a-zA-Z0-9@:%._\\+~#?&//=]*)");

    htmlcxx::HTML::ParserDom parser;
    tree<htmlcxx::HTML::Node> dom = parser.parseTree(html);
    for (auto it = dom.begin(); it != dom.end(); ++it){
        if (it->tagName() == "a"){
            it->parseAttributes();
            std::string url = it->attribute("href").second;

            if (url.find(".pdf") == std::string::npos){
                if (std::regex_match(url, domain)){
                    out_urls->push_back(url);
                }
                if (std::regex_match(url, subpath)){
                    out_urls->push_back("https://www.ifb.edu.br" + url);
                }
            } else {
                out_pdfs->insert(url);
            }
        }
    }
}