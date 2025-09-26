#include <stdio.h>
#include "strprocess.h"

struct Contatto {
    char nome[31];
    char cognome[31];
    char tel[21];
};

void nameIn(char* s) {
    scanf("%30s",s);
    clean(s,true);
}

void telIn(char* s) {
    scanf("%20s",s);
    clean(s,false);
}

int main(void) {
    int scelta = 0;
    struct Contatto rubrica[100];
    do {
        printf("1 - aggiungi un nuovo contatto\n");
        printf("2 - visualizza tutti i contatti\n");
        printf("3 - cerca per cognome\n");
        printf("4 - elimina contatto per cognome\n");
        printf("0 - esci\n");
        printf("Inserisci comando: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                // aggiungi contatto
                break;
            case 2:
                // stampa la lista di contatti
                break;
            case 3:
                // cerca
                break;
            case 4:
                // elimina
                break;
            case 0:
                printf("Chiusura del programma in corso...\n");
                break;
            default:
                printf("Inserisci un numero tra 0 e 4\n");
                break;
        }
    } while (scelta != 0);
    return 0;
}