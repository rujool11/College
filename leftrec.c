#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char input[50];
char* prod[50];

char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 1));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left] = '\0';
    return subStr;
}

int countDel(char* input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '|') { count++; }
    }
    return count;
}

int* findind(char* str)
{
    int length = strlen(str);
    int* indexes = NULL;
    int indexCount = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == '|')
        {
            indexCount++;
            indexes = (int*)realloc(indexes, indexCount * sizeof(int));
            indexes[indexCount - 1] = i;
        }
    }

    return indexes;
}

bool isLeftRecursive(char* input)
{
    return (input[0] == input[3]); 
}

void removeLeftRecursion(char* input){
    char NT = input[0];
    int* dellocs = findind(input);

    if (dellocs == NULL)
    {
        prod[0] = subString(input, 4, strlen(input) - 1);
        printf("%c->%c'\n",NT,NT);
        printf("%c'->%s%c'|∊\n",NT,prod[0],NT);
        return;
    }

    int delimiterCount = countDel(input);
    int st = dellocs[0];
    char in[strlen(input)+2];
    for (int i=0;i<strlen(input);i++){
        if (i<st){in[i]=input[i];}
        else if (i==st){in[i]=input[i];
        in[i+1]='.';
        in[i+2]='|';}
        else if (i>st){
            in[i+2] = input[i];
        }
    }
    delimiterCount = countDel(in);
    dellocs = findind(in);

    for (int i = 0; i <delimiterCount; i++)
    {
        if (i == 0)
        {
            prod[i] = subString(in, 4, dellocs[i]);
        }
        else if (i == delimiterCount - 1)
        {
            prod[i] = subString(in, dellocs[i] + 1, strlen(in) - 1);
        }
        else
        {
            prod[i] = subString(in, dellocs[i] + 1, dellocs[i + 1]);
        }
    }
    printf("%c->",NT);
    for (int i=1;i<delimiterCount;i++){
        if (i==delimiterCount-1){
        printf("%s%c'",prod[i],NT);
        }
        else{
        printf("%s%c'|",prod[i],NT);
        }
        if (i==delimiterCount-1){
            printf("\n%c'->%s%c'|∊\n",NT,prod[0],NT);
        
    }
    }
}

void process(char* input)
{
    if (!isLeftRecursive(input))
    {
        printf("21BCT0263 No left recursion in the production\n");
        printf("\n\t%s\n", input);
    }
    else
    {
        removeLeftRecursion(input);
    }
    return;
}

int main()
{
    printf("21BCT0263 Rujool Patil\n");
    printf("21BCT0263 Enter production\n");
    fgets(input, sizeof(input), stdin);

    process(input);
    return 0;
}
