#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool mflag = false;
bool pflag = false;
bool sflag = false;

char input[50];

bool has(char* x,char c){
    bool val = false;
    for (int i=0;i<strlen(x);i++){
        if (x[i]==c){ val = true; }
    }
    return val;
}

bool isBefore(char* x,char a,char b){
    int ain,bin;
    for (int i=0;i<strlen(x);i++){
        if (x[i]==a){ ain = i;}
        else if (x[i]==b){ bin = i;}
    }
    return (ain>bin);
}

void parse(char* input){
    printf("21BCT0263 Operator precedence set-'*' has higher precedence , then'-' and then '+'\n");
    // for (int i=0;i<strlen(input);i++){
    while (!mflag||!pflag||!sflag){
        if (has(input,'*')&&!mflag){
            mflag = true;
            printf("21BCT0263 E*E\n");
            if (has(input,'-')&&isBefore(input,'*','-')&&!sflag){
                sflag = true;
                printf("21BCT0263 E-E*E\n");
                if (has(input,'+')&&isBefore(input,'-','+')&&!pflag){
                    pflag = true;
                    printf("21BCT0263 E+E-E*E\n");
                }
                else if (has(input,'+')&&!isBefore(input,'-','+')&&!pflag){
                    pflag = true;
                    printf("E-E+E*E\n");
                }
            }
            else if (has(input,'-')&&!isBefore(input,'*','-')&&!sflag){
                sflag = true;
                printf("21BCT0263 E*E-E\n");
                if (has(input,'+')&&isBefore(input,'*','+')&&!pflag){
                    pflag = true;
                    printf("21BCT0263 E+E*E-E\n");
                }
                else if (has(input,'+')&&!isBefore(input,'*','+')&&isBefore(input,'-','+')&&!pflag){
                    pflag = true;
                    printf("21BCT0263 E*E+E-E\n");
                }
                else if (has(input,'+')&&isBefore(input,'*','+')&&!isBefore(input,'-','+')&&!pflag){
                    pflag = true;
                    printf("21BCT0263 E*E-E+E\n");
                }
            }
            else if (has(input,'+')&&!pflag){
                pflag = true;
                if (isBefore(input,'*','+')){
                    printf("21BCT0263 E+E*E\n");
                }
                else{
                    printf("21BCT0263 E*E+E\n");
                }
            }
        }
        else if (has(input,'-')&&!sflag){
            sflag = true;
            printf("21BCT0263 E-E\n");
            if (has(input,'+')&&!pflag){
                pflag = true;
                if (isBefore(input,'+','-')){
                    printf("21BCT0263 E-E+E\n");
                }
                else{
                    printf("21BCT0263 E+E-E\n");
                }
            }
        }
        else if (!strcmp(input,"id+id\n")){
            printf("21BCT0263 E+E\n");
        }
        else{ 
            return; }
        
    }
}

int main(){
    printf("21BCT0263 Removal of ambiguity in operator grammar\n");
    printf("21BCT0263 enter the required string \n");
    fgets(input,sizeof(input),stdin);
    parse(input);
    return 0;
}