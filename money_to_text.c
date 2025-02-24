#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "money_to_text.h"

// number to words conversion arrays
const char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// convert number to words function
void number_to_words(int num, char* buffer) {
    buffer[0] = '\0';

    if (num == 0) {
        strcpy(buffer, "zero");
        return;
    }

    if (num >= 1000) {
        strcat(buffer, ones[num / 1000]);
        strcat(buffer, " thousand ");
        num %= 1000;
    }

    if (num >= 100) {
        strcat(buffer, ones[num / 100]);
        strcat(buffer, " hundred ");
        num %= 100;
    }

    if (num >= 20) {
        strcat(buffer, tens[num / 10]);
        if (num % 10) {
            strcat(buffer, "-");
            strcat(buffer, ones[num % 10]);
        }
    } else if (num >= 10) {
        strcat(buffer, teens[num - 10]);
    } else if (num > 0) {
        strcat(buffer, ones[num]);
    }
}

// convert money to text function
void convert_money(int cents, char* output) {
    int dollars = cents / 100;
    int remaining_cents = cents % 100;

    char dollars_text[100], cents_text[100];

    number_to_words(dollars, dollars_text);
    number_to_words(remaining_cents, cents_text);

    // if cents is 0, only print dollars, otherwise print both dollars and cents
    if (remaining_cents == 0) {
        sprintf(output, "%s dollars.", dollars_text);
    } else {
        sprintf(output, "%s dollars and %s cents.", dollars_text, cents_text);
    }
}
