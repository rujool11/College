#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char input[50];

int table[7][5];

struct stack {
    char* data;
    int top;
};

struct stack createStack() {
    struct stack s;
    s.data = (char*)malloc(50 * sizeof(char));
    s.top = -1;
    return s;
}

char pop(struct stack* s) {
    return s->data[s->top--];
}

void push(struct stack* s, char x) {
    s->data[++s->top] = x;
}

void showStacko(struct stack s) {
    for (int i = 0; i <= s.top; i++) {
        printf("%c", s.data[i]);
    }
}

void showStacki(struct stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%c", s.data[i]);
    }
}

struct sitem {
    int atS;
    int atA;
    int ata;
    int atb;
    int atD;
};

struct ritem {
    char* foll;
    int prod;
    int folllen;
};

int findind(char x) {
    char string[6] = "ab$AS";
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == x) {
            return i;
        }
    }
    return -1;
}

struct sitem zero, two, three;
struct ritem one, four, five, six;

void constructLRitems() {
    zero.atS = 1;
    zero.atA = 2;
    zero.ata = 3;
    zero.atb = 4;
    zero.atD = 0;

    two.atS = 0;
    two.atA = 5;
    two.ata = 3;
    two.atb = 4;
    two.atD = 0;

    three.atS = 0;
    three.atA = 6;
    three.ata = 3;
    three.atb = 4;
    three.atD = 0;

    one.foll = (char*)malloc(sizeof(char));
    one.folllen = 1;
    one.foll[0] = '$';
    one.prod = -50; // denotes accept state

    four.foll = (char*)malloc(4 * sizeof(char));
    four.folllen = 3;
    four.foll[0] = 'a';
    four.foll[1] = 'b';
    four.foll[2] = '$';
    four.prod = -3;

    five.foll = (char*)malloc(sizeof(char));
    five.folllen = 1;
    five.foll[0] = '$';
    five.prod = -1;

    six.foll = (char*)malloc(4 * sizeof(char));
    six.folllen = 3;
    six.foll[0] = 'a';
    six.foll[1] = 'b';
    six.foll[2] = '$';
    six.prod = -2;
}

void sfill(int x, struct sitem s) {
    table[x][0] = s.ata;
    table[x][1] = s.atb;
    table[x][2] = s.atD;
    table[x][3] = s.atA;
    table[x][4] = s.atS;
}

void rfill(int x, struct ritem s) {
    for (int i = 0; i < s.folllen; i++) {
        table[x][findind(s.foll[i])] = s.prod;
    }
}

int toInt(char x) {
    return (int)(x - '0');
}

char toChar(int x) {
    return (char)(x + '0');
}

bool isNum(char x) {
    char nums[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 10; i++) {
        if (nums[i] == x) {
            return true;
        }
    }
    return false;
}

void maketable() {
    constructLRitems();
    for (int i = 0; i < 7; i++) {
        switch (i) {
        case 0:
            sfill(0, zero);
            break;
        case 1:
            rfill(1, one);
            break;
        case 2:
            sfill(2, two);
            break;
        case 3:
            sfill(3, three);
            break;
        case 4:
            rfill(4, four);
            break;
        case 5:
            rfill(5, five);
            break;
        case 6:
            rfill(6, six);
            break;
        default:
            break;
        }
    }
}

void Reduce(struct stack* pistack, struct stack* pibuff) {
    int tval = table[toInt(pistack->data[pistack->top])][findind(pibuff->data[pibuff->top])];

    switch (tval) {
    case -1:
        printf("Reduce S->AA\n");
        for (int i = 0; i < 4; i++) {
            pop(pistack);
        }
        push(pistack, 'S');
        break;

    case -2:
        printf("Reduce A->aA\n");
        for (int i = 0; i < 4; i++) {
            pop(pistack);
        }
        push(pistack, 'A');
        break;

    case -3:
        printf("Reduce A->b\n");
        pop(pistack);
        pop(pistack);
        push(pistack, 'A');
        break;

    default:
        break;
    }
}

bool compare(struct stack* pistack, struct stack* pibuff) {
    int tval = table[toInt(pistack->data[pistack->top])][findind(pibuff->data[pibuff->top])];

    if (tval == -50) {
        printf("Accepted\n");
        return true;
    }
    else if (tval == 0) {
        printf("Not Accepted\n");
        return true;
    }

    if (tval > 0) {
        printf("push %c and %c\n", pibuff->data[pibuff->top], toChar(tval));
        push(pistack, pop(pibuff));
        push(pistack, toChar(tval));
    }
    else if (tval < 0) {
        Reduce(pistack, pibuff);
    }

    return false;
}

void parse(char* input) {
    maketable();

    struct stack istack = createStack();
    struct stack ibuff = createStack();

    push(&istack, '0');
    push(&ibuff, '$');

    for (int i = strlen(input) - 1; i >= 0; i--) {
        push(&ibuff, input[i]);
    }

    printf("STACK\t\tIPBUFFER\t\tACTION\n");
    int top = 0;
    while (true && ++top != 50) {
        if (isNum(istack.data[istack.top])) {
            showStacko(istack);
            printf("\t\t");
            showStacki(ibuff);
            printf("\t\t");
            bool end = compare(&istack, &ibuff);
            if (end) {
                return;
            }
        }
        else {
            showStacko(istack);
            printf("\t\t");
            showStacki(ibuff);
            printf("\t\tpush %c\n",toChar(table[toInt((istack.data[istack.top - 1]))][findind(istack.data[istack.top])])); 
            push(&istack, toChar(table[toInt(istack.data[istack.top - 1])][findind(istack.data[istack.top])]));
        }
    }
}

int main() {
    printf("21BCT0263 Rujool Patil SLR\n");
    printf("21BCT0263 enter string to parse\n");
    fgets(input, sizeof(input), stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    parse(input);
    return 0;
}
