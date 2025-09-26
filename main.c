#include <stdio.h>
#include "strprocess.h"

#define SEPLEN 40

struct Contatto {
    char nome[31];
    char cognome[31];
    char tel[21];
};

void separate(int len) {
    for (int i = 0; i < len; i++) {
        printf("-");
    }
    printf("\n");
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
                char nome[31] = "";
                char cognome[31] = "";
                char tel[21] = "";
                int nl = 0;
                int cl = 0;
                int tl = 0;
                do {
                    printf("Inserisci nome: ");
                    nl = nameIn(nome);
                } while (nl == 0);
                do {
                    printf("Inserisci cognome: ");
                    cl = nameIn(cognome);
                } while (cl == 0);
                do {
                    printf("Inserisci n. telefono: ");
                    tl = telIn(tel);
                } while (tl == 0);
                separate(SEPLEN);
                printf("nome: ");
                strOut(nome);
                printf("\n");
                printf("cognome: ");
                strOut(cognome);
                printf("\n");
                printf("num. telefono: ");
                strOut(tel);
                printf("\n");
                separate(SEPLEN);
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