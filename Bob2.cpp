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
int decrypt(int ciphertext, long long d, long long n) {
    return power(ciphertext, d, n);
}

int main() {
    int d;
    int n;
    int c;
    std::cout<<"enter d: ";
    cin>>d;
    std::cout<<endl<<"enter n: ";
    cin>>n;
    std::cout<<endl<<"enter ciphertext: ";
    cin>>c;
    
    std::cout<<"decrypted message: "<<decrypt(c,d,n)<<endl;
    return 0;
}