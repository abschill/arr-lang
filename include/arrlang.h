#include <stdlib.h>
#include <string.h>
#include "color.h"

char _cache[] = {};

void print_cache() {
    printf("\n");
    style(*yellow, "cache:\n");
    printf("%s", _cache);
    printf("\n");
}

void append_char(char c, int pos, int ln) {
    char last_two[2] = {_cache[pos-1], c};
    // print char, line&position
    // todo: actually parse lol
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
}
