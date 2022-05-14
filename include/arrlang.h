#include <stdlib.h>
#include <string.h>
#include "color.h"

char _cache[] = {};

char C_OPEN_SCOPE = "$";
char C_ASSIGN_TAG = "=";
int D_SIZE = 4;
char* D_TOKENS[D_SIZE] = {C_OPEN_SCOPE, C_ASSIGN_TAG};

void check_tokens(char* acc, int i_size) {
    printf("%s\n", acc);
    for(int i=0; i <= i_size; i++) {
        printf("%d\n", i);
    }
}

void print_cache() {
    printf("\n");
    style(*yellow, "cache:\n");
    printf("%s", _cache);
    printf("\n");
}

void append_char(char c, int pos, int ln) {
    char last_two[2] = {_cache[pos-1], c};
    strcat(_cache, &c);
    style(*purple, "Character: ");
    printf("%c\n", c);
    style(*yellow, "Line: ");
    printf("%d\n", ln);
    style(*yellow, "Position: ");
    printf("%d\n", pos);
    // -1 pos for last char + this char
    printf("Last 2: %s\n\n", last_two);
    print_cache();
    check_tokens(_cache, pos);
}
