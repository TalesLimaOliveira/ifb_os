#ifndef CRAWLER_H
#define CRAWLER_H

/**
 * @brief Crawler thread function that processes URLs and scrapes content.
 * 
 * @param arg Argument passed to the thread.
 * @return void* 
 */
void* crawler(void* arg);

#endif // CRAWLER_H