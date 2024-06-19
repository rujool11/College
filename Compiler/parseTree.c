#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data[10];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isOperator(char c) {
    return (c == '+' || c == '*');
}

struct Node* buildParseTree(char* expression, int start, int end) {
    if (start > end)
        return NULL;

    struct Node* root = NULL;

    if (start == end) {
        char id[10];
        int j = 0;
        for (int i = start; i <= end; i++) {
            id[j++] = expression[i];
        }
        id[j] = '\0';
        if (strcmp(id, "id") == 0)
            strcpy(id, "i");
        root = createNode(id);
        return root;
    }

    int count = 0;
    int minPrecedence = 1000;
    int minPrecedenceIndex = -1;

    for (int i = start; i <= end; i++) {
        if (expression[i] == '(')
            count++;
        else if (expression[i] == ')')
            count--;
        else if (isOperator(expression[i]) && count == 0) {
            int precedence = 0;
            if (expression[i] == '+')
                precedence = 1;
            else if (expression[i] == '*')
                precedence = 2;

            if (precedence <= minPrecedence) {
                minPrecedence = precedence;
                minPrecedenceIndex = i;
            }
        }
    }

    if (minPrecedenceIndex != -1) {
        char op[2];
        op[0] = expression[minPrecedenceIndex];
        op[1] = '\0';
        root = createNode(op);
        root->left = buildParseTree(expression, start, minPrecedenceIndex - 1);
        root->right = buildParseTree(expression, minPrecedenceIndex + 1, end);
    }

    return root;
}

void printParseTreeLevels(struct Node* root, int level) {
    if (root == NULL)
        return;

    printf("\n");
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%s", root->data);

    printParseTreeLevels(root->left, level + 1);
    printParseTreeLevels(root->right, level + 1);
}

int main() {
    char expression[100];

    printf("21BCT0263 parse tree construction\n");
    printf("21BCT0263 enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    int length = 0;
    while (expression[length] != '\0')
        length++;

    struct Node* root = buildParseTree(expression, 0, length - 2);

    printf("21BCT0263 Parse Tree with Levels:\n");
    printParseTreeLevels(root, 0);

    return 0;
}
