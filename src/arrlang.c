#include <stdio.h>

void handle_inline(char c, int pos, int ln) {
    // print char, line&position 
    // todo: actually parse lol
    printf("Character: %c\n", c);
    printf("Line: %d & Position: %d\n", ln, pos);
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
            handle_inline(c, file_pos, line_no);
        }
        // get next char in stream
        c = fgetc(content);
    }
    printf("\n");
    // close stream
    fclose(content);
    return 0;
}