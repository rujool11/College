#include <iostream>
using namespace std;

int maxSubSum(int* a,int length){
    int maxSum = 0,currSum = 0;
    for (int i=0;i<length;i++){
        currSum += a[i];

        if (currSum>maxSum) { maxSum = currSum;}
        if (currSum < 0){ currSum = 0;}
    }
    return maxSum;

}

int main(){
    int l;
    cout<<"enter length "<<endl;
    cin>>l;
    int arr[l];
    for (int i=0;i<l;i++){
        cin>>arr[i];
    }
    cout<<maxSubSum(arr,l);
    return 0;
}