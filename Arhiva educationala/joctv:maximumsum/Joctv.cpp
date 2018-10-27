#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("joctv.in");
ofstream fout("joctv.out");

#define DM 105

int n,m[DM][DM],sp[DM][DM];

int main() {
    fin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            fin >> m[i][j];
            sp[i][j] = sp[i - 1][j] +  m[i][j];
        }
    }
    
    int maxsum = -99999999;
    for(int i1 = 1; i1 <= n; i1++) {
        for(int i2 = i1; i2 <= n; i2++) {
            int sum = 0;
            for(int j = 1; j <= n; j++) {
                int c = sp[i2][j] - sp[i1 - 1][j];
                if(sum < 0) {
                    sum = c;
                }else {
                    sum += c;
                }
                maxsum = max(sum,maxsum);
            }
        }
    }
    
    fout << maxsum;
    
}
