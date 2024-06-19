//write a program to find transpose of a matrix
#include <stdio.h>
int main(){
    int rows,cols;
    printf("enter the rows and columns: ");
    scanf("%d %d",&rows,&cols);
    int m[rows][cols], transpose[cols][rows];
    printf("enter the matrix");
    for (int p=0;p<rows;p++){
        for (int q=0;q<cols;q++){
            scanf("%d ",&m[p][q]);
        }
        printf("\n");
    }
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            m[i][j]=transpose[j][i];
        }
    }
    for (int p=0;p<rows;p++){
        for (int q=0;q<cols;q++){
            printf("%d ",transpose[p][q]);
        }
        printf("\n");
    }

return 0;}