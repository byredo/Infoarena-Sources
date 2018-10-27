#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

int n,k;
int v[20],u[20];

void combinari(int poz) {
    if(poz == k + 1) {
        for(int i = 1; i < poz; i++) {
            fout << v[i] << " ";
        }
        fout << '\n';
        return;
    } else {
        for(int i = v[poz - 1]; i <= n; i++) {
            if(!u[i]) {
                v[poz] = i;
                u[i] = 1;
                combinari(poz + 1);
                u[i] = 0;
            }
        }
    }
}

int main() {
    fin >> n >> k;
    v[0] = 1;
    combinari(1);
}
