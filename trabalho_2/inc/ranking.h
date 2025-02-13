#ifndef RANKING_H
#define RANKING_H

/**
 * @brief Function executed by the ranking thread to update and display the ranking of files.
 * 
 * @param arg Unused parameter.
 * @return void* Always returns NULL.
 */
void* ranking_function(void* arg);

/**
 * @brief Comparison function for qsort to sort FileCount in descending order.
 */
int compare_file_counts(const void* a, const void* b);

/**
 * @brief Updates the ranking of files based on the count of term occurrences and prints the top results.
 */
void update_ranking();

#endif//RANKING_H