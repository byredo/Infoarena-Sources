#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

int n;
int v[20];
bool used[20];

void gperm(int p) {
    if(p == n + 1) {
        for(int i = 1; i <= n; i++) {
            fout << v[i] << " ";
        }
        fout << '\n';
    } else {
        for(int i = 1; i <= n; i++) {
            if(!used[i]) {
                used[i] = 1;
                v[p] = i;
                gperm(p + 1);
                used[i] = 0;
            }
        }
    }
}

int main() {
    fin >> n;
    for(int i = 1; i <= n; i++) {
        v[i] = i;
    }
    
    gperm(1);
}
