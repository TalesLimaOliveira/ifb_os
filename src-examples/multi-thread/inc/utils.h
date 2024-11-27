#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <unordered_set>
#include <vector>

// External declarations for color codes
extern std::string default_color;
extern std::string color_codes[];

/**
 * @brief Displays the current date and time in a specific color format.
 */
void display_current_date_time();

/**
 * @brief Callback function for handling data received from a CURL request.
 * 
 * @param buffer Pointer to the data received.
 * @param size Size of each data element.
 * @param nmemb Number of data elements.
 * @param user_pointer Pointer to the user data.
 * @return size_t Size of the data processed.
 */
size_t buffer_callback(char* buffer, size_t size, size_t nmemb, void* user_pointer);

/**
 * @brief Makes an HTTP request to the specified URL and returns the response as a string.
 * 
 * @param url The URL to request.
 * @return std::string The response from the server.
 */
std::string request(const std::string& url);

/**
 * @brief Scrapes the HTML content for URLs and PDFs, storing them in the provided containers.
 * 
 * @param html The HTML content to scrape.
 * @param out_urls Pointer to a vector to store found URLs.
 * @param out_pdfs Pointer to an unordered set to store found PDFs.
 */
void scrape(const std::string& html, std::vector<std::string>* out_urls, std::unordered_set<std::string>* out_pdfs);

#endif // UTILS_H