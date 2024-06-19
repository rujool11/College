#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define alphabets 2
#define states 4
char a[10];
char b[10];
char c[10];
char d[10];
char e[10];
char f[10];
char g[10];

char* NFAtable[states][alphabets] = {
    {"01", "0"},
    {"2", "1"},
    {"3", "3"},
    {" ", "2"}
};

char* DFAtable[5][alphabets];

void convert() {
    printf("\n21BCT0263 original NFA transition table:\n\n");
    printf("\t0\t1\n");
    for (int i = 0; i < states; i++) {
        if (strcmp(NFAtable[i][0], " ") == 0) {
            printf("q%d\tphi\tq%s\n", i, NFAtable[i][1]);
        }
        else {
            printf("q%d\tq%s\tq%s\n", i, NFAtable[i][0], NFAtable[i][1]);
        }
    }

    printf("\n21BCT0263 converted DFA transition table:\n\n");

    for (int i = 0; i < 5; i++) {
        DFAtable[i][0] = (char*)malloc(10 * sizeof(char));
        DFAtable[i][1] = (char*)malloc(10 * sizeof(char));

        if (i == 0) {
            strcpy(DFAtable[i][0], NFAtable[i][0]);
            strcpy(DFAtable[i][1], NFAtable[i][1]);
        }
        else if (i == 1) {
            strcpy(a,DFAtable[0][0]);
            strcpy(b,DFAtable[0][1]);
            strcpy(DFAtable[i][0], strcat(a,NFAtable[1][0]));
            strcpy(DFAtable[i][1], strcat(b,NFAtable[1][1]));
        }
        else if (i == 2) {
            strcpy(c,DFAtable[1][0]);
            strcpy(d,DFAtable[0][0]);
            strcpy(DFAtable[i][0], strcat(c,NFAtable[2][0]));
            strcpy(DFAtable[i][1], strcat(d,NFAtable[2][1]));
        }
        else if (i == 3) {
            strcpy(e,DFAtable[1][0]);
            strcpy(DFAtable[i][0],DFAtable[i - 1][0]);
            strcpy(DFAtable[i][1],strcat(e,NFAtable[2][1]));
        }
        else if (i == 4) {
            strcpy(f,DFAtable[0][0]);
            strcpy(g,DFAtable[0][0]);
            strcpy(DFAtable[i][0], strcat(f,NFAtable[1][0]));
            strcpy(DFAtable[i][1], strcat(g,NFAtable[1][0]));
        }
    }
}

int main() {
    printf("21BCT0263 Rujool Patil NFA to DFA\n");
    convert();
    printf("qabc represents a new state qaqbqc\n");
    printf("21BCT0263 final NFA transition table: \n");
    printf("\t0\t1\n");
    for (int i = 0; i < 5; i++) {
        if (i==0){
        printf("q%d\tq%s\tq%s\n",i, DFAtable[i][0], DFAtable[i][1]);
        }
        else if (i==4){
        printf("q%s\tq%s\tq%s\n",DFAtable[i-2][1], DFAtable[i][0], DFAtable[i][1]);
        }
        else{
        printf("q%s\tq%s\tq%s\n",DFAtable[i-1][0], DFAtable[i][0], DFAtable[i][1]);
        }
    }

    for (int i = 0; i < 5; i++) {
        free(DFAtable[i][0]);
        free(DFAtable[i][1]);
    }

    return 0;
}