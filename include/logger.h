#pragma once
#include <stdlib.h>
#include <string.h>
#include "colors.h"

char _cache[] = {};

char token_map[4][2] = {
    '$', '='
};

void check_tokens(char* acc, int i_size) {
    for(int i=0; i <= i_size; i++) {
        //printf("%d\n", i);
    }
}

void print_cache() {
    printf("\n");
    printf("%s%s", yellow.text, "cache:\n");
    printf("%s", _cache);
    printf("%s", COLOR_RESET);
    printf("\n");
}

void append_char(char c, int pos, int ln) {
    char last_two[2] = {_cache[pos-1], c};
    strcat(_cache, &c);
    printf("%s%s", purple.text, "Character: ");
    printf("%s", COLOR_RESET);
    printf("%c\n", c);
    printf("%s%s", yellow.text, "Line: ");
    printf("%s", COLOR_RESET);
    printf("%d\n", ln);
    printf("%s%s", yellow.text, "Position: ");
    printf("%s", COLOR_RESET);
    printf("%d\n", pos);
    // -1 pos for last char + this char
    printf("%sLast 2:%s %s\n\n", purple.underline, COLOR_RESET, last_two);
    print_cache();
    check_tokens(_cache, pos);
}
