#ifndef CACHE_H
#define CACHE_H

#define MAX_CACHE_SIZE 150000
#define CACHE_FILE "cache.txt"

void init_cache();
char* find_in_cache(int amount);
void add_to_cache(int amount, const char* text);
void save_cache();

#endif
