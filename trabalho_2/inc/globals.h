#ifndef GLOBALS_H
#define GLOBALS_H

#define MAX_WORKERS 10
#define MAX_FILES 100
#define MAX_FILENAME 256
#define TOP_N 10

typedef struct {
    char filename[MAX_FILENAME];
    int count;
} FileCount;

extern pthread_mutex_t lock;
extern pthread_cond_t cond;
extern char term[256];
extern FileCount file_counts[MAX_FILES];
extern int file_count;
extern int worker_available[MAX_WORKERS];
extern int directory_check_count;

#endif // GLOBALS_H