#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char input[50];
char trash[50];
int tcount = -1;
//21BCT0263 Rujool Patil
// S->CC
// C->cC | d


struct stack{

    char* data;
    int top;
};

struct stack createStack(){

    struct stack s;
    s.data = (char *)malloc(50*sizeof(char));
    s.top = -1;
    return s;
}

char pop(struct stack* s){

    return s->data[s->top--];
}

void push(struct stack* s,char x){

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

void parse(char* input){
    
    struct stack istack = createStack();
    struct stack ibuff = createStack();
    
    push(&istack,'$');
    push(&ibuff,'$');
    
    for (int i=strlen(input)-1;i>=0;i--){
        if (input[i]!='c' && input[i]!='d'){
            printf("21BCT0263 symbols can only be c or d, ILLEGAL symbol\n");
            return;
        }
        push(&ibuff,input[i]);
    }

    printf("STACK\t\tINPUTBUFF\t\tACTION\n");
    int iterc = 0;
    while (true && ++iterc<=50){

        
        if (istack.data[istack.top]=='S'&&ibuff.data[ibuff.top]=='$'){

            showStacko(istack);
            printf("\t\t");
            showStacki(ibuff);
            printf("\t\t");
            printf("Accepted\n");
            break;
        }


        else if (istack.data[istack.top] == 'd'){

            showStacko(istack);
            printf("\t\t");
            showStacki(ibuff);
            printf("\t\t");
            trash[++tcount] = pop(&istack);
            push(&istack,'C');
            printf("Reduce C->d\n");
        }       
        
        else if (istack.data[istack.top] == 'C' && (istack.data[istack.top-1]=='C'||istack.data[istack.top-1]=='c')){
            
            int onet = istack.top - 1;
            if (istack.data[onet] == 'C'){
                showStacko(istack);
                printf("\t\t");
                showStacki(ibuff);
                printf("\t\t");
                trash[++tcount] = pop(&istack);
                trash[++tcount] = pop(&istack);
                push(&istack,'S');
                printf("Reduce S->CC\n");

            }
            else if (istack.data[onet] == 'c'){
                showStacko(istack);
                printf("\t\t");
                showStacki(ibuff);
                printf("\t\t");
                trash[++tcount] = pop(&istack);
                trash[++tcount] = pop(&istack);
                push(&istack,'C');
                printf("Reduce C->cC\n");

            }

        }
        else if (ibuff.data[ibuff.top] == '$'){
            showStacko(istack);
            printf("\t\t");
            showStacki(ibuff);
            printf("\t\t");
            printf("Not Accepted\n");
            return;

        }
        else{

                showStacko(istack);
                printf("\t\t");
                showStacki(ibuff);
                printf("\t\t");
                push(&istack,pop(&ibuff));
                printf("\t\t");
                printf("Shift\n");
            }
        

    }
}

int main(){

    printf("21BCT0263 Rujool Patil Shift Reduce Parsing\n");
    printf("21BCT0263 enter the string to be parsed\n");
    fgets(input,sizeof(input),stdin);
    if (input[strlen(input)-1]=='\n'){
        input[strlen(input)-1] = '\0';
    }
    parse(input);
    return 0;
}