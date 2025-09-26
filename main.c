#include <stdio.h>
#include <string.h>

#include "strprocess.h"

#define SEPLEN 40

struct Contatto {
    char nome[31];
    char cognome[31];
    char tel[21];
};

int findContact(struct Contatto r[100], char *s) {
    int i = 0;
    while (i < 100) {
        if (!strcmp(s, r[i].cognome)) return i;
        i++;
    }
    return -1;
}

void printContact(struct Contatto r[100], int i) {
    struct Contatto c = r[i];
    printf("Nome: ");
    strOut(c.nome);
    printf("\nCognome: ");
    strOut(c.cognome);
    printf("\nTelefono: ");
    strOut(c.tel);
    printf("\n");
}

void separate(int len) {
    for (int i = 0; i < len; i++) {
        printf("-");
    }
    printf("\n");
}

int main(void) {
    int scelta = 0;
    struct Contatto rubrica[100];
    int nContatti = 0;
    printf("RUBRICA by Camilla");
    do {
        printf("\n1 - aggiungi un nuovo contatto\n");
        printf("2 - visualizza tutti i contatti\n");
        printf("3 - cerca per cognome\n");
        printf("4 - elimina contatto per cognome\n");
        printf("0 - esci\n");
        printf("Inserisci comando: ");
        scanf("%d", &scelta);
        char nome[31] = "";
        char cognome[31] = "";
        char tel[21] = "";
        switch (scelta) {
            case 1:
                // aggiungi contatto
                do {
                    printf("Inserisci nome: ");
                } while (!nameIn(nome));
                do {
                    printf("Inserisci cognome: ");
                } while (!nameIn(cognome));
                do {
                    printf("Inserisci n. telefono: ");
                } while (!telIn(tel));
                int pos = findContact(rubrica, cognome);
                if (pos == -1) {
                    struct Contatto c;
                    strcpy(c.nome, nome);
                    strcpy(c.cognome, cognome);
                    strcpy(c.tel, tel);
                    rubrica[nContatti] = c;
                    printContact(rubrica,nContatti);
                    nContatti++;
                } else {
                    strOut(cognome);
                    printf(" esiste gia'\n");
                }
                break;
            case 2:
                // stampa la lista di contatti
                printf("tutti i contatti\n");
                if (!nContatti) {
                    separate(SEPLEN);
                    printf("la rubrica e' vuota\n");
                }
                for (int i = 0; i < nContatti; i++) {
                    separate(SEPLEN);
                    printContact(rubrica, i);
                }
                break;
            case 3:
                // cerca
                do {
                    printf("Inserisci cognome da cercare: ");
                } while (!nameIn(cognome));
                pos = findContact(rubrica, cognome);
                if (pos != -1) {
                    printf("Trovato 1 contatto: \n");
                    printContact(rubrica, pos);
                }
                else {
                    strOut(cognome);
                    printf(" non trovato");
                }
                break;
            case 4:
                // elimina
                do {
                    printf("Inserisci cognome: ");
                } while (!nameIn(cognome));
                pos = findContact(rubrica, cognome);
                if (pos != -1) {
                    for (int i = pos; i < nContatti; i++) {
                        rubrica[i] = rubrica[i + 1];
                    }
                    nContatti--;
                }
                else {
                    strOut(cognome);
                    printf(" non esiste\n");
                }
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