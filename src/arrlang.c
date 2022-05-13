
#include <stdlib.h>
#include <string.h>
#include "color.c"

char _cache[] = {};

void append_char(char c, int pos, int ln) {
    char last_two[2] = {_cache[pos-1], c};
    // print char, line&position
    // todo: actually parse lol
    strcat(_cache, &c);
    purple();
    printf("Character: ");
    reset();
    printf("%c\n", c);
    yellow();
    printf("Line: ");
    reset();
    printf("%d\n", ln);
    yellow();
    printf("Position: ");
    reset();
    printf("%d\n", pos);
    // -1 pos for last char + this char
    printf("Last 2: %s\n\n", last_two);
}

void print_cache() {
    printf("\n");
    yellow();
    printf("input file:\n");
    reset();
    printf("%s", _cache);
    printf("\n");
}

int main(int argc, char*argv[]) {
    int file_pos = 0;
    int line_no = 0;
    char* input_file;
    char c;

    // if no input arg then just run the test file for now
    if(argc == 1) {
        input_file = "example0.arr";
    }
    else {
        if(argc == 2)
            input_file = argv[1];
    }
    FILE* content = fopen(input_file, "r");
    // get file by each char as a stream
    c = fgetc(content);
    while(c != EOF) {
        // inc the pos for every char in the stream
        file_pos++;
        append_char(c, file_pos, line_no);
        if(c == '\n') {
            // if its a line break inc the line no
            line_no++;
            printf("\n");
        }
        // get next char in stream
        c = fgetc(content);
    }
    print_cache();
    // close stream
    fclose(content);
    return 0;
}