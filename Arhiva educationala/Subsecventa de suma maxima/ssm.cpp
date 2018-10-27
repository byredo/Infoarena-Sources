#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

#define DM 6000001

int n,v[DM];
int best[DM];

int main() {
    fin >> n;
    for(int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    
    int  inceput, sfarsit, maxsum = -int(2e9), index = 0,sum = 0;
    best[1] = v[1];
    for(int i = 2; i <= n; i++) {
        if(sum < 0) {
            sum = v[i];
            index = i;
        }else {
            sum += v[i];
        }
        
        if(maxsum < sum) {
            maxsum = sum;
            inceput = index;
            sfarsit = i;
        }
    }
    
    fout << maxsum << " " << inceput << " " << sfarsit;
}
