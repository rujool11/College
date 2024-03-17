#include <iostream>
using namespace std;

string encrypt(string& message, int key){

    key = key%26;

    for (auto &x: message){
        if (isalpha(x)){
            if (islower(x)){
                x = ((x - 'a' + key)%26) + 'a';
            }
            else if (isupper(x)){
                x = ((x - 'A' + key)%26) + 'A';
            }
        }
    }
    
    return message;
}

int main(){
    string message;
    int key;

    cout<<"enter the message : ";
    cin>>message;
    cout<<"entert the key : ";
    cin>>key;

    cout<<encrypt(message,key)<<endl;

    return 0;

}