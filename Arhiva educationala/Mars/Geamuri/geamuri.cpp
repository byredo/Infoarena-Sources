#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("geamuri.in");
ofstream fout("geamuri.out");

int c,n,x1,y1,x2,y2,m,ki;
int mars[1030][1030];
int fm[1030][1030];
int aux[1030][1030];
int fr[100001];

int main() {
    fin >> c >> n;
    for(int i = 1; i <= n; i++) {
        fin >> x1 >> y1 >> x2 >> y2;
        mars[x1][y1]++;
        mars[x1][y2 + 1]--;
        mars[x2 + 1][y1]--;
        mars[x2 + 1][y2 + 1]++;
    }
    
    for(int i = 1; i <= c; i++) {
        for(int j = 1; j <= c; j++) {
            fm[i][j] += mars[i][j] + fm[i][j - 1] + fm[i - 1][j] - fm[i - 1][j - 1];
            fr[fm[i][j]]++;
        }
    }
    
    fin >> m;
    for(int i = 1; i <= m; i++) {
        fin >> ki;
        fout << fr[ki] << '\n';
    }
    
}
