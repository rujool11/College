#include <iostream>
using namespace std;
#define n 4

void Solution(int board[n][n]){
    int i,j;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (board[i][j]){
                cout<<"Q ";
            }
            else {
                cout<<". ";
            }
        }
        cout<<endl;
    }

}

bool Checker(int board[n][n],int row,int col){
    int i,j;
    for (i=0;i<col;i++){
        if (board[row][i]){return false;}
    }
    for (i=row,j=col;i>=0 && j>=0;i--,j--){
        if (board[i][j]) {return false;}
    }
    for (i=row,j=col;j>=0 && i<n;j--,i++ ){
        if (board[i][j]){return false;}
    }
    return true;
}

bool util(int board[n][n], int col){
    if (col>=n){return true;}
    for (int i=0;i<n;i++){
        if (Checker(board,i,col)){
            board[i][col] = 1;
            if (util(board,col+1)){return true;}
            board[i][col] = 0;
        }
    }
    return false;
}

void NQueens(){
    int board[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }
    if (util(board,0)){
        Solution(board);
        return;
    }
    cout<<"no solution exists";
    return;
}

int main(){
    NQueens();
    return 0;
}