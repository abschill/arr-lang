#include "logger.h"


void parse_file(char* s, int file_pos, int line_no) {
    char c;
    FILE* content = fopen(s, "r");
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
    // close stream
    fclose(content);
}

int main(int argc, char*argv[]) {
    // if no input arg then just run the test file for now
    if(argc <= 1) {
        fprintf(stderr, "%sarrlang%s: No Input File. exiting\n", red.text, COLOR_RESET);
        exit(1);
    }
    char* input_file = argv[1];
    int file_pos = 0;
    int line_no = 0;
    parse_file(input_file, file_pos, line_no);
    return 0;
}
