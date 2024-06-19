#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* subString(char* str,int l,int r){
    char* out = (char*)malloc(sizeof(char)*(r-l+2));
    int outind = -1;
    for(int i=l;i<=r;i++){
        out[++outind] = str[i];
    }
    out[++outind] = '\0';
    return out;
}

bool isLR(const char* str){
    return (str[0] == str[3]);
}

void removeLR(char* str){
    char NT = str[0];
    if (!isLR(str)){
        printf("21BCT0263 No left recursion: %s", str);
        return;
    }

    char* alpha = (char*)malloc(sizeof(char) * 50);
    char* beta = (char*)malloc(sizeof(char) * 50);

    int i = 4;
    int alphaIndex = 0;
    while (str[i] != '|' && str[i] != '\0'){
        alpha[alphaIndex++] = str[i++];
    }
    alpha[alphaIndex] = '\0';

    if (str[i] == '|') {
        int betaIndex = 0;
        i++; 
        while (str[i] != '\0'){
            beta[betaIndex++] = str[i++];
        }
        beta[betaIndex] = '\0';
    }

    printf("%c->%s%c'\n",NT,beta,NT);
    printf("%c'->%s%c'|∈\n",NT,alpha,NT);
    free(alpha);
    free(beta);
}

int main(){
    char input[50];
    printf("21BCT0263 Rujool Patil removal of left recursion\n");
    printf("21BCT0263 enter the grammar to parse separated by a comma\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    if (strcspn(input,",")!=strlen(input)){
    char* i1 = subString(input,0,strcspn(input,",")-1);
    char* i2 = subString(input,strcspn(input,",")+1,strlen(input));
    removeLR(i1);
    removeLR(i2);
    }
    else{
    removeLR(input);
    }
    return 0;
}
