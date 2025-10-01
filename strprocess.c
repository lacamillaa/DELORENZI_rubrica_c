#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int getCharType(char c) {
    if (c == 0) {
        return -1;
    }
    if (c == '\n') {
        return 0;
    }
    if (c == ' ') {
        // spazio = 1
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        // lettera maiuscola = 2
        return 2;
    }
    if (c >= 'a' && c <= 'z') {
        // lettera minuscola = 3
        return 3;
    }
    if (c >= '0' && c <= '9') {
        // carattere numerico = 4
        return 4;
    }
    if (c == '+') {
        return 5;
    }
    return 0;
}

int nameIn(char* s) {
    fflush(stdin);
    char c = getchar();
    int i = 0;
    while (getCharType(c) && i < 30) {
        if (!getCharType(c)) {
            // new line
            s[i] = 0;
            break;
        }
        if (getCharType(c) <= 3) {
            s[i] = c;
            i++;
        }
        c = getchar();
    }
    return i;
}

int telIn(char* s) {
    char c = 0;
    int i = 0;
    bool usedPre = false;
    while (getCharType(c) && i < 20) {
        c = (char)getchar();
        switch (getCharType(c)) {
            case 0:
                s[i] = 0;
                break;
            case 1: case 4:
                // spazio o numero
                s[i] = c;
                i++;
                break;
            case 5:
                // + del prefisso
                if (i == 0) {
                    s[0] = c;
                    i++;
                }
                break;
            default:
                break;
        }
    }
    return i;
}

void strOut(char* s) {
    int i = 0;
    while (s[i] != 0) {
        printf("%c",s[i]);
        i++;
    }
}

int charCmp(char s1, char s2) {
    if (getCharType(s1) == 2) {
        s1 += ' ';
    }
    if (getCharType(s2) == 2) {
        s2 += ' ';
    }
    const int diff = s1 - s2;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int strCmp(char* s1, char* s2) {
    int res = 0;
    // se s1 = s2 => 0
    // se s1 > s2 => 1
    // se s1 < s2 => -1
    // Camillp
    // Camill
    // s1 > s2 => 1
    int i = 0;
    // individua la parte comune
    for (i = 0; !res && i <= strlen(s1) && i <= strlen(s2); i++) {
        res = charCmp(s1[i], s2[i]);
    }
    res = charCmp(s1[i], s2[i]);
    return res;
}

int findStr(char arr[][31], char* str, int s, int e, int l) {
    int m = (s + e + 1) / 2;
    if (e < s) return -1;
    if (str[l] == 0) return m;
    if (arr[m][l] == 0) return -1;
    if (s == e) {
        printf("%d - %d\n", arr[m][l], str[l]);
        if (arr[m][l] != str[l]) return -1;
        l++;
    }
    else {
        if (arr[m][l] > str[l]) {
            // R, C => sx
            e = m - 1;
        } else if (arr[m][l] < str[l]) {
            // C, R
            s = m + 1;
        } else {
            // C, C
            l++;
        }
    }
    return findStr(arr, str, s, e, l);
}

int insertPos(char arr[][31], char* str, int s, int e) {
    // e incluso
    int m = (s + e) / 2;
    int r = strCmp(arr[m],str);
    if (s == e) return m;
    if (r == -1) {
        s = m + 1;
    }
    else if (r == 0) {
        return m;
    }
    else {
        e = m;
    } return insertPos(arr, str, s, e);
}