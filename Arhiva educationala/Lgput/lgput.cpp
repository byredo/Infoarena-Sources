#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("lgput.in");
ofstream fout("lgput.out");

#define MOD 1999999973

long long n,p;
long long inplus = 1, rez;

long long putere(long long  n, long long p) {
    if(p == 1) {
        return n;
    } else {
        if(p % 2 == 1) {
            inplus *= n;
            inplus %= MOD;
        }
        rez = putere((n * n) % MOD, p / 2) % MOD;
    }
    return rez % MOD;
}

int main() {
    fin >> n >> p;
    fout << (1LL * putere(n, p) * inplus) % MOD;
}
