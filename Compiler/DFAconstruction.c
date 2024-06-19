#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define alphabetobjects 2
// (a|b)*ab is the regex

char* regex = "(a+b)*.a.b.#";
char* regexRev = "#.b.a.(b+a)*";
char* idsregex = "(1+2)*.3.4.5";
int tt[][alphabetobjects] = {{1,0},{1,2},{1,0}};

void calculateFollow(char ch){
    for (int i=0;i<strlen(idsregex);i++){
        if (ch==idsregex[i] && idsregex[i+1]=='.'){
            printf("21BCT0263 follow of %c is %c\n",ch,idsregex[i+2]);
            break;
        }
        else if (ch=='#'){
            printf("21BCT0263 end of string symbol , no follow\n");
            break;
        }
        else if (ch==idsregex[i] && (idsregex[i+1]==')'|| idsregex[i+1]=='+')){
            printf("21BCT0263 follow of %c is (%c,%c,%c)\n",ch,idsregex[1],idsregex[3],idsregex[7]);
            break;
        }
    }
}

void DFAdesc(){
    printf("21BCT0263 States -> q0(1,2,3)\n");
    printf("21BCT0263 q1(1,2,3,4)\n");
    printf("21BCT0263 q2(1,2,3,5)\n");
    
}

void TransTable(){
    printf("\t a \t b\n");
    for (int i=0;i<3;i++){
        printf("q%d\tq%d\tq%d\n",i,tt[i][0],tt[i][1]);
    }
}

bool DFAAcceptance(int tt[][alphabetobjects],char input[]){
    int currState = 0; //start state
    for (int i=0;i<strlen(input);i++){
        if (input[i] == 'a'){
            currState = tt[currState][0];
        }
        else if (input[i] == 'b'){
            currState = tt[currState][1];
        }
        else{
            printf("use valid input symbol\n");
            return 0;
        }
    }

    printf("final state : q%d\n",currState);
    if (currState==2){return true;}
    return false;
}


int main(){
    printf("21BCT0263 Rujool Patil\n21BCT0263 Regex is: (a|b)*ab (any string ending with ab)\n");
    printf("21BCT0263 ids : 1->a\n21BCT0263 2->b\n21BCT0263 3->a\n21BCT0263 4->b\n21BCT0263 5-># (end symbol)\n");
    char input[50];
    calculateFollow('1');
    calculateFollow('2');
    calculateFollow('3');
    calculateFollow('4');
    calculateFollow('#');
    printf("\n\n");
    DFAdesc();
    printf("\n\n");
    TransTable();
    printf("\n\n");
    printf("21BCT0263 enter the string to be parsed: ");
    scanf("%s",input);
    if (DFAAcceptance(tt,input)){printf("21BCT0263 DFA has been accepted\n");}
    else{
        printf("21BCT0263 DFA has not been accepted\n");
    }
    return 0;
}