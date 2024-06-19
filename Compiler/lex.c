#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
char delimiter[] = {' ',',', ';', '/', '[', ']', '{', '}', '(', ')', '=', '<', '>', '-', '+', '*'};
int desize = 16;
char operator[] = {'+', '-', '=', '/', '*', '<', '>'};
int opsize = 7;
char identifierInvalidStarts[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int idsize = 10;
char substrarr[][50];
int subind = 0;

bool inArray(char arr[], char a,int arrsize){
    for (int i = 0; i <= arrsize; i++){
        if (arr[i] == a){
            return true;
        }
    }
    return false;
}

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||!strcmp(str,"for")
        || !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "bool")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto") || !strcmp(str,"main")){
        return (true);}
    return (false);
}

 
bool isInteger(char* str)
{
    int i, len = strlen(str);
 
    if (len == 0){
        return (false);}
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0)){
            return (false);}
    }
    return (true);
}

bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

bool isDelimiter(char in)
{
    if (inArray(delimiter,in,desize)){return true;}
    return false;
}
 
bool isOperator(char in){
    if (inArray(operator,in,opsize)){return true;}
    return false;
}
 
bool validIdentifier(char* str)
{
    if (inArray(identifierInvalidStarts,str[0],idsize) || isDelimiter(str[0]) == true){
        return (false);}
    return (true);
}

void parse(char* str)
{
    int check=0;
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
 
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true){;}
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right|| (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
            strcpy(substrarr[++subind],subStr);

            if (isKeyword(subStr) == true){
                
                if (!strcmp(subStr,"if")){
                    printf("21BCT0263 contitional statement\n");
                    return;
                }
                else if (!strcmp(subStr,"for")|| !strcmp(subStr,"while")){
                    printf("21BCT0263 looping statement\n");
                    printf("21BCT0263 %s loop is used\n",subStr);
                    return;
                } 
                else if (!strcmp(subStr,"int")||!strcmp(subStr,"float")||!strcmp(subStr,"bool")||!strcmp(subStr,"char")){
                    printf("21BCT0263 Declarative Statement\n");
                    printf("21BCT0263 variable is of %s data type\n",subStr);
                    return;

                } 
                }
 
            else if (isInteger(subStr) == true){;}
 
            else if (isRealNumber(subStr) == true){;}
 
            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false){
                printf("21BCT0263 expression statement\n");
                return;
            }
            
 
            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false){
                printf("21BCT0263 ERROR : invalid identifier %s'\n", subStr);
            }

            left = right; 
        }
    }
    return;
    
}

int main(){
    printf("Rujool Patil 21BCT0263\n");
    char str[100];
    int i=-1;
    printf("21BCT0263 enter the program in a single line and with a '$' appended at the end\n");
    do {
        i++;
        str[i] = getchar();
    }while (str[i]!='$');
    str[i-1] = '\0';
    parse(str); 
    return 0;
}