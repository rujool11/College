#include <iostream>
using namespace std;

void sort(int* end,int* start,int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if (end[j]>end[j+1]){
                swap(end[j],end[j+1]);
                swap(start[j],start[j+1]);
            }
        }
    }
}

void selection(int* start,int* end,int n){
    sort(end,start,n);
    int k = 0;
    cout<<"Selected ----"<<endl;
    cout<<"start : "<<start[k]<<" end : "<<end[k]<<endl;
    
    for (int j=1;j<n;j++){
        if (start[j]>=end[k]){
            cout<<"start : "<<start[j]<<" end : "<<end[j]<<endl;
            k = j;
        }
    }

}
 
int main(){
    int n;
    cin>>n;
    int start[n],end[n];
    for (int i=0;i<n;i++){
        cin>>start[i]>>end[i];
    }
    selection(start,end,n);

    return 0;
}