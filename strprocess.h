#ifndef STRPROCESS_H
    #define STRPROCESS_H
#endif
#include <stdbool.h>

int getCharType(char c);

int nameIn(char* s);

int telIn(char* s);

void strOut(char* s);

int charCmp(char s1, char s2);

int strCmp(char* s1, char* s2);

int findStr(char arr[][31], char* str, int s, int e, int l);

int insertPos(char arr[][31], char* str, int s, int e);