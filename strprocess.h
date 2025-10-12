#ifndef STRPROCESS_H
    #define STRPROCESS_H
#endif

int getCharType(char c);

int nameIn(char* s);

int telIn(char* s);

void strOut(char* s);

int charCmp(char s1, char s2);

int firstPos(char list[100][31], char str[31], int s, int e);

int findPos(char list[100][31], char str[31], int s, int e);

int lastPos(char list[100][31], char str[31], int e);