#include <stdbool.h>

int getCharType(char c) {
    if (c == 0) {
        return -1;
    }
    else if (c == ' ') {
        // spazio = 1
        return 1;
    }
    else if (c >= 'A' && c <= 'Z') {
        // lettera maiuscola = 2
        return 2;
    }
    else if (c >= 'a' && c <= 'z') {
        // lettera minuscola = 3
        return 3;
    }
    else if (c >= '0' && c <= '9') {
        // carattere numerico = 4
        return 4;
    }
    else if (c == '+') {
        return 5;
    }
    else return 0;
}

void clean(char s[], bool name) {
    int j = 0;
    for (int i = 0; s[i] != 0; i++) {
        int type = getCharType(s[j]);
        if (!type || (type > 4 && name)) j++;
        s[i] = s[j];
        j++;
    }
}