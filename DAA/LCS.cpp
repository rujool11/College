#include <iostream>
using namespace std;

int LCS(string a,string b,int m, int n){
    int L[m+1][n+1];
    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
            if (i==0 || j == 0){
                L[i][j] = 0;
            }
            else if (a[i-1] == b[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else {
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    return L[m][n];

}

int main(){
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();
    cout<<LCS(S1,S2,m,n);

    return 0;

}