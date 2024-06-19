#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char delbuff[50];
int k = -1;
char input[50];

int table[5][5] = {
    {1,-1,-1,-1,1},
    {1,1,-1,-1,1},
    {1,1,1,-1,1},
    {1,1,1,1,1},
    {-1,-1,-1,-1,0}
};

int findind(char x){
    char a[5] =  "|&~i$";
    int res = -1;
    for (int i=0;i<strlen(a);i++){
        if (a[i]==x){ res = i;}
    }
    return res;
}

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

bool isTerminal(char c){
    if (c == '&'||c == 'i'||c == '~' || c == '|'||c == '$'){return true;}
    return false;
}

void push(struct stack *s, char a) {
    s->data[++s->top] = a;
}

char pop(struct stack *s) {
    if (s->top<0){printf("underflow"); 
    return -1;}
    return s->data[s->top--];
}

void showstacki(struct stack s){
    for (int i=s.top;i>=0;i--){
        printf("%c",s.data[i]);
    }
}

void showstacko(struct stack s){
    for (int i=0;i<=s.top;i++){
        printf("%c",s.data[i]);
    }
}

void shift(int p,struct stack* pistack,struct stack* pibuff){
    showstacko(*pistack);
    printf("\t\t");
    showstacki(*pibuff);
    printf("\t\t");
    printf("Shift (%c<%c)\n",pistack->data[pistack->top],pibuff->data[pibuff->top]);
    push(pistack,pop(pibuff));
    return;
}

void reduce(int p,struct stack* pistack,struct stack* pibuff,int ttemp){
    showstacko(*pistack);
    printf("\t\t");
    showstacki(*pibuff);
    printf("\t\t");
    printf("Reduce (%c>%c)\n",pistack->data[pistack->top],pibuff->data[pibuff->top]);
    if (pistack->data[ttemp]=='i'){
        delbuff[++k] = pop(pistack);
        push(pistack,'E');
    }
    else if (pistack->data[ttemp]=='~'){
        delbuff[++k] = pop(pistack);
        delbuff[++k] = pop(pistack);
        push(pistack,'E');
    }
    else{
        delbuff[++k] = pop(pistack);
        delbuff[++k] = pop(pistack);
        delbuff[++k] = pop(pistack);
        push(pistack,'E');
    }

}

void parse(char* input){
    struct stack istack = createStack();
    struct stack ibuff = createStack();
    push(&istack,'$');
    push(&ibuff,'$');
    for (int i=strlen(input)-1;i>=0;i--){
        push(&ibuff,input[i]);
    }
    int p;
    char ichar;
    int ttemp = istack.top;
    printf("STACK\t\tBUFFER\t\tACTION\n");
    while (true){
        while (!isTerminal(istack.data[ttemp])){
            ttemp--;
        }
        ichar = findind(istack.data[ttemp]);
        p = table[ichar][findind(ibuff.data[ibuff.top])];
        switch(p){
            case 0:
                showstacko(istack);
                printf("\t\t");
                showstacki(ibuff);
                printf("\t\t");
                if (istack.data[istack.top]=='E'&&istack.top==1){
                printf("Accepted\n");}
                else{
                    printf("Not Accepted\n");
                }
                return;
                break;
            case 1:
                reduce(p,&istack,&ibuff,ttemp);
                ttemp = istack.top;
                break;
            case -1:
                shift(p,&istack,&ibuff);
                ttemp = istack.top;
                break;
        }
    }
}

int main(){
    printf("21BCT0263 Rujool Patil\n");
    printf("21BCT0263 enter the string to parse\n");
    fgets(input,sizeof(input),stdin);
    if (input[strlen(input)-1]=='\n'){input[strlen(input)-1] = '\0';}
    parse(input);
    return 0;
}