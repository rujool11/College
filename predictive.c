#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char input[50];

struct stack {
    char* data;
    int top;
};

struct stack createStack() {
    struct stack s;
    s.data = (char *)malloc(50 * sizeof(char));
    s.top = -1;
    return s;
}

void push(struct stack *s, char a) {
    s->data[++s->top] = a;
}

void pop(struct stack *s) {
    s->top--;
}

void showStacko(struct stack s) {
    for (int i = 0; i <= s.top; i++) {
        printf("%c", s.data[i]);
    }
}

void showStacki(struct stack s) {
    printf("\t\t");
    for (int i = s.top; i >= 0; i--) {
        printf("%c", s.data[i]);
    }
}

char firstS[1] = {'a'};
char firstA[2] = {'c', '.'};
char firstB[2] = {'d', '.'};
char follS[1] = {'$'};
char follA[2] = {'d', 'b'};
char follB[1] = {'b'};
int parseTable[3][5];

int findinda(char x) {
    char* string = "abcd.";
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == x) {
            return i;
        }
    }
    return -1;
}

int findindb(char x) {
    char* string = "SAB";
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == x) {
            return i;
        }
    }
    return -1;
}

void maketable() {
    for (int i = 0; i < 1; i++) {
        parseTable[0][findinda(firstS[i])] = 1;
    }
    for (int i = 0; i < 2; i++) {
        if (firstA[i] == '.') {
            for (int j = 0; j < 2; j++) {
                parseTable[1][findinda(follA[j])] = 3;
            }
        } else {
            parseTable[1][findinda(firstA[i])] = 2;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (firstB[i] == '.') {
            for (int j = 0; j < 1; j++) {
                parseTable[2][findinda(follB[j])] = 5;
            }
        } else {
            parseTable[2][findinda(firstB[i])] = 4;
        }
    }
}

void aux(int x) {
    switch (x) {
        case 1:
            printf("\tS->aABb");
            break;
        case 2:
            printf("\tA->c");
            break;
        case 3:
            printf("\tA->∊");
            break;
        case 4:
            printf("\tB->d");
            break;
        case 5:
            printf("\tB->∊");
            break;
        default:
            printf("\t");
            break;
    }
}

void showtable() {
    printf("21BCT0263 parsing table for the grammar: \n\n");
    printf("\t\ta\tb\tc\td\t∊\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 0) {
                printf("S\t");
            } else if (i == 1 && j == 0) {
                printf("A\t");
            } else if (i == 2 && j == 0) {
                printf("B\t");
            }
            aux(parseTable[i][j]);
        }
        printf("\n");
    }
}

void parse(char* string) {
    maketable();
    showtable();
    printf("\n\n");
    struct stack istack = createStack();

    int len = strlen(string);
    for (int i = len - 2; i >= 0; i--) {
        push(&istack, string[i]);
    }
    
    int a;
    struct stack ostack = createStack();
    push(&ostack, '$');
    push(&ostack, 'S');
    printf("Stack\t\tInputBuffer\t\tComment\n");
    
    while (true) {
        if (istack.data[istack.top] == '$' && ostack.data[ostack.top] == '$') {
            showStacko(ostack);
            showStacki(istack);
            printf("\t\t\tAccepted\n");
            return;
        }
        else if (parseTable[findindb(ostack.data[ostack.top])][findinda(istack.data[istack.top])] != 0) {
                a = parseTable[findindb(ostack.data[ostack.top])][findinda(istack.data[istack.top])];
                showStacko(ostack);
                showStacki(istack);
                printf("\t\t");
                aux(a);
                printf("\tPop %c, Push ", ostack.data[ostack.top]);
                
                switch (a) {
                    case 1:
                        printf("bBAa\n");
                        pop(&ostack);
                        push(&ostack, 'b');
                        push(&ostack, 'B');
                        push(&ostack, 'A');
                        push(&ostack, 'a');
                        break;
                    case 2:
                        printf("c\n");
                        pop(&ostack);
                        push(&ostack, 'c');
                        break;
                    case 3:
                        printf("∊\n");
                        pop(&ostack);
                        break;
                    case 4:
                        printf("d\n");
                        pop(&ostack);
                        push(&ostack, 'd');
                        break;
                    case 5:
                        printf("∊\n");
                        pop(&ostack);
                        break;
                }
        } 
        else if (istack.data[istack.top]==ostack.data[ostack.top]){
            showStacko(ostack);
            showStacki(istack);
            printf("\t\t\tpop %c\n", istack.data[istack.top]);
            pop(&ostack);
            pop(&istack);
        }
        else{
            showStacko(ostack);
            showStacki(istack);
            printf("\t\t\tNot Accepted\n");
            return;
        }
    }
}

int main() {
    printf("21BCT0263 Rujool Patil LL(1) Predective Parser\n");
    printf("21BCT0263 epsilon denoted by '.'\n");
    printf("21BCT0263 enter the string to parse\n");
    fgets(input, sizeof(input), stdin);
    parse(input);
    return 0;
}
