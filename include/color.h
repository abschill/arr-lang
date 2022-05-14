#include <stdio.h>

typedef void (*cb)(void);

void reset() {
    printf("\033[0;37m");
}

void red() {
    printf("\033[0;31m");
}

void green() {
    printf("\033[0;32m");
}

void yellow() {
    printf("\033[0;33m");
}

void blue() {
    printf("\033[0;34m");
}

void purple() {
    printf("\033[0;35m");
}

void cyan() {
    printf("\033[0;36m");
}

void style(cb _cb, char* msg) {
    (*_cb)();
    printf("%s", msg);
    reset();
}
