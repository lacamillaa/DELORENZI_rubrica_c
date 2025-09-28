#ifndef STRPROCESS_H
    #define STRPROCESS_H
#endif
#include <stdbool.h>

int getCharType(char c);

int nameIn(char* s);

int telIn(char* s);

void strOut(char* s);

int findStr(char** arr, char* str, int s, int e, int l);