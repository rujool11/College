#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int counter = 0;
//Rujool Patil 21BCT0263
//Grammar
// S -> A
// A -> X
// A -> abX
// X -> ab|bX|Aa|epsilon

bool X(char* word,int pt,int len){

    if (word[len-1]=='a'){
        printf("\t\tX -> Aa\n");
        word[len-1] = '\0';
        len--;
        if (word[pt]=='a'&& word[pt+1]=='b'){
        printf("\t\tA->abX\n");
        pt += 2;
        X(word,pt,len);
    }
    else{
        printf("\t\tA->X\n");
        X(word,pt,len);
    }
    }
    else if (word[pt]=='a'&&word[pt+1]=='b'){
        printf("\t\tX -> ab\n");
        pt+=2;
        if (pt==len){
        printf("\t\tAccepted\n");
        counter ++;
        return true;
        }
    }
    
    else if (word[pt]=='b'){
        printf("\t\tX->bX\n");
        X(word,++pt,len);
    }
    else if (pt==len){
        printf("\t\tX->epsilon\n");
        printf("\t\tAccepted\n");
        counter++;
        return true;
    }
    return false;
}

bool A(char* word,int pt,int len){
    if (word[pt]=='a'&& word[pt+1]=='b'){
        printf("\t\tA->abX\n");
        pt += 2;
        X(word,pt,len);
    }
    else{
        printf("\t\tA->X\n");
        X(word,pt,len);
    }
}

bool S(char* word,int pt,int len){
    A(word,pt,len);
}


bool RecursiveDescent(char* word,int len){
    int pt=0;
    bool runner = S(word,pt,len);
    if(counter==0){
        printf("\t\tNot Accepted\n");
    }
}

int main(){
    char str[100];
    int i = -1;
    printf("21BCT0263 enter the string in a single line and with a '$' appended at the end\n");
    do {
        i++;
        str[i] = getchar();
    }while (str[i]!='$');
    str[i] = '\0';
    RecursiveDescent(str,strlen(str));
    return 0;
}

