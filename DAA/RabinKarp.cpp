#include <iostream>
#include <string.h>
using namespace std;
#define d 26 //number of characters in the alphabet

void RK(char* pat,char* txt,int q){
    int M = strlen(pat);
    int N = strlen(txt);
    int i,j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i=0;i<M-1;i++){
        h = (h*d)%q;
    }

    for (i=0;i<M;i++){
        p = (p*d + pat[i])%q;
        t = (t*d + txt[i])%q;
    }

    for (i=0;i<N-M;i++){
        if (p==t){
            for (j=0;j<M;j++){
                if (txt[i+j]!=pat[j]){break;}
            }
            if (j==M){
                cout<<"Pattern found at index "<<i<<endl;
            }
        }
    }

    if  (i<N-M){
        t = (d*(t-txt[i]*h) + txt[i+M])%q;
    }
    
    if (t<0){t+=q;}
}

int main(){
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = INT8_MAX;  // or whatever is given
    RK(pat, txt, q);
    return 0;
}