#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache.h"

// memoization structure
typedef struct {
    int amount;
    char text[100];
} CacheEntry;

CacheEntry cache[MAX_CACHE_SIZE];
int cache_size = 0;

// number_to_words function prototype
char* number_to_words(int num, char* buffer);

// initialize cache from file
void init_cache() {
    FILE* file = fopen(CACHE_FILE, "r");
    if (file) {
        while (fscanf(file, "%d %[^\n]", &cache[cache_size].amount, cache[cache_size].text) != EOF) {
            cache_size++;
        }
        fclose(file);
    }
}

// save cache to file
void save_cache() {
    FILE* file = fopen(CACHE_FILE, "a");
    if (file) {
        for (int i = 0; i < cache_size; i++) {
            fprintf(file, "%d %s\n", cache[i].amount, cache[i].text);
        }
        fclose(file);
    }
}

// find cached result
char* find_in_cache(int amount) {
    for (int i = 0; i < cache_size; i++) {
        if (cache[i].amount == amount) {
            return cache[i].text;
        }
    }
    return NULL;
}

// add unsaved result to cache
void add_to_cache(int amount, const char* text) {
    if (cache_size < MAX_CACHE_SIZE) {
        cache[cache_size].amount = amount;
        strcpy(cache[cache_size].text, text);
        cache_size++;
    }
}