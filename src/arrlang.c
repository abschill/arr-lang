#include <stdio.h>

int main(int argc, char*argv[]) {
    char* input_file;
    char c;
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
        if(c == '\n') {
            printf("\n");   
        }
        else {
            printf("%c", c);
        }
        c = fgetc(content);
    }
    printf("\n");
    fclose(content);
    return 0;
}