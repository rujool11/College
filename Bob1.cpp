#include <iostream>
#include <random>
#include <cmath>
#include <bitset>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


int generatePrime(int e) {
    random_device rd;
    mt19937 gen(rd());

    cout << "Decimal\tBinary\t\tIsPrime?\tIs (p-1) % e == 0?" << endl;

    int p = uniform_int_distribution<int>(0, 255)(gen); // random 8 bit number

    // Check if p is prime, if not, add 2 and try again
    while (!isPrime(p)) {
        bitset<8> x(p); // Update x inside the loop
        cout << p << "\t" << x << "\t  false\t\t" << (((p - 1) % e == 0) ? "true" : "false") << endl;
        p += 2;
    }

    // Check if (p-1) is co-prime with e=17
    if ((p - 1) % e == 0) {
        p += 2;
    }

    bitset<8> x(p); // Update x before printing the final result
    cout << p << "\t" << x << "\t  " << (isPrime(p) ? "true" : "false") << "\t\t" << (((p - 1) % e == 0) ? "true" : "false") << endl;
    return p;
}


int calculateN(int p ,int q)  { return p*q; }

int calculateTotient(int p,int q) { return (p-1)*(q-1); }

int calculateD(int e, int z) {
    
    for (int d=1;d<z;d++){
        if ((d*e)%z == 1) return d;
    }

    return -1;
}

void doEverything(int e) {
    int p = generatePrime(e);
    int q = generatePrime(e);
    
    while (p==q) q = generatePrime(e);

    int n  = calculateN(p,q);

    int z = calculateTotient(p,q);

    int d = calculateD(e,z);

    cout<<"p: "<<p<<endl;
    cout<<"q: "<<q<<endl;
    cout<<"n: "<<n<<endl;
    cout<<"z (totient): "<<z<<endl;
    cout<<"public key: ["<<e<<";"<<n<<"]"<<endl;
    cout<<"private key: ["<<d<<";"<<n<<"]"<<endl;
}


int main()
{
    int e;
    cout << "the encryption exponent: ";
    cin >> e;
    doEverything(e);
    return 0;
}