#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate (base^exp) % mod
int power(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to encrypt plaintext using RSA
int encrypt(int plaintext, long long e, long long n) {
    return power(plaintext, e, n);
}

int main() {
    int e;
    int n;
    int m;
    std::cout<<"enter e: ";
    cin>>e;
    std::cout<<endl<<"enter n: ";
    cin>>n;
    std::cout<<endl<<"enter message: ";
    cin>>m;
    
    std::cout<<"encrypted message: "<<encrypt(m,e,n)<<endl;
    return 0;
}
