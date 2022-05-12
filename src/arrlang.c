#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char _cache[] = {};

void append_char(char c, int pos, int ln) {
    char last_two[2] = {_cache[pos-1], c};
    // print char, line&position 
    // todo: actually parse lol
    strcat(_cache, &c);
    printf("Character: %c\n", c);
    printf("Line: %d & Position: %d\n", ln, pos);
    // -1 pos for last char + this char
    printf("Last 2: %s\n", last_two);
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
        if(c == '\n') {
            // if its a line break inc the line no
            line_no++;
            printf("\n");   
        }
        else {
            
            append_char(c, file_pos, line_no);
        }
        // get next char in stream
        c = fgetc(content);
    }
    printf("\n");
    printf("The File:\n");
    printf("%s", _cache);
    // close stream
    fclose(content);
    return 0;
}