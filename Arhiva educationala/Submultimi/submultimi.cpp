#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int v[17];
bool used[17];
int n;
int j;
int answers;

void bkt(int poz) {
    if(poz == j + 1) {
        for(int i = 1; i <= j; i++) {
            fout << v[i] << " ";
        }
        fout << '\n';
    } else {
        for(int i = v[poz - 1]; i <= n; i++) {
            if(!used[i]) {
                v[poz] = i;
                used[i] = true;
                bkt(poz + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    fin >> n;
    v[0] = 1;
    for(j = 1; j <= n; j++) {
        bkt(1);
    }
}
