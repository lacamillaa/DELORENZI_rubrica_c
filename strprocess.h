#ifndef STRPROCESS_H
    #define STRPROCESS_H
#endif
#include <stdbool.h>

int getCharType(char c);

int nameIn(char* s);

int telIn(char* s);

void strOut(char* s);

int charCmp(char s1, char s2);

// trova la 1^ posizione in cui un elemento compare in un array
int firstPos(char list[100][31], char str[31], int s, int e);