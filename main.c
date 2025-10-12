#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strprocess.h"

#define SEPLEN 40

struct Contatto {
    char nome[31];
    char cognome[31];
    char tel[21];
};

int findContact(char cognomi[100][31], char cognome[31], char nomi[100][31], char nome[31], int lim) {
    int cPos = findPos(cognomi, cognome, 0, lim);
    if (cPos == -1) return -1;
    int lcPos = lastPos(cognomi, cognome, lim);
    int nPos = findPos(nomi, nome, cPos, lcPos);
    return nPos;
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
    char cognomi[100][31];
    char nomi[100][31];
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
        if (scelta == 1) {
            if (nContatti == 100) {
                printf("Memoria esaurita\n");
            }
            else {
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
                int pos = findContact(cognomi, cognome, nomi, nome, nContatti);
                if (pos == -1) {
                    struct Contatto c;
                    strcpy(c.nome, nome);
                    strcpy(c.cognome, cognome);
                    strcpy(c.tel, tel);
                    int fp = firstPos(cognomi, c.cognome, 0, nContatti);
                    int lp = lastPos(cognomi, c.cognome, nContatti);
                    fp = firstPos(nomi, nome, fp, lp);
                    for (int i = nContatti; i > fp; i--) {
                        rubrica[i] = rubrica[i-1];
                        strcpy(cognomi[i], cognomi[i-1]);
                        strcpy(nomi[i], nomi[i-1]);
                    }
                    rubrica[fp] = c;
                    strcpy(cognomi[fp],c.cognome);
                    strcpy(nomi[fp],c.nome);
                    printContact(rubrica,fp);
                    nContatti++;
                } else {
                    strOut(cognome);
                    printf(" ");
                    strOut(nome);
                    printf(" esiste gia'\n");
                }
            }
        } else if (scelta == 2) {
            // stampa la lista di contatti
            printf("tutti i contatti\n");
            if (!nContatti) {
                printf("la rubrica e' vuota\n");
            }
            for (int i = 0; i < nContatti; i++) {
                separate(SEPLEN);
                printContact(rubrica, i);
            }
        } else if (scelta == 3) {
            // cerca
            do {
                printf("Inserisci cognome da cercare: ");
            } while (!nameIn(cognome));
            int pos = findContact(cognomi, cognome, nomi, nome, nContatti);
            if (pos != -1) {
                printf("Trovato 1 contatto: \n");
                printContact(rubrica, pos);
            }
            else {
                strOut(cognome);
                printf(" non trovato");
            }
        } else if (scelta == 4) {
            // elimina
            do {
                printf("Inserisci cognome: ");
            } while (!nameIn(cognome));
            int pos = findContact(cognomi, cognome, nomi, nome, nContatti);
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
        } else if (scelta == 0) {
            printf("Chiusura del programma in corso...\n");
        } else {
            printf("Inserisci un numero tra 0 e 4\n");
        }
    } while (scelta != 0);
    return 0;
}