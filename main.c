#include <stdio.h>
#include <stdlib.h>
#include "cache.h"
#include "money_to_text.h"

int main() {
    int amount;

    // initialize cache
    init_cache();

    // read input from file
    while (scanf("%d", &amount) != EOF) {
        if (amount < 0) {
            printf("Amount must be a positive integer.\n");
            continue;
        }

        // find cached result
        char* cached_text = find_in_cache(amount);
        if (cached_text) {
            printf("%d = %s\n", amount, cached_text);
            continue;
        }

        // convert amount of money to text
        char buffer[100];
        convert_money(amount, buffer);

        printf("%d = %s\n", amount, buffer);

        // if amount is less than 150000, add and save it to cache
        if (amount < 150000) {
            add_to_cache(amount, buffer);
            save_cache();
        }
    }

    return 0;
}
