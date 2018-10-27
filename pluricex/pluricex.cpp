#include <fstream>

using namespace std;

ifstream fin("pluricex.in");
ofstream fout("pluricex.out");

int n,k,d;
int nrd[23];
int fr[13];
int elev[23][11]; // disciplinele la care participa elevul
int used[10], sol[10];

void bkt(int pas) {
    if(pas == k + 1) {
        bool ok = true;
        for(int i = 1; i <= d; i++) {
            if(!fr[i]) {
                ok = false;
            }
        }
        
        if(ok) {
            for(int i = 1; i <= k; i++)
                fout << sol[i] << " ";
            fout << '\n';
        }
        
        
        return;
    } else {
        for(int i = sol[pas - 1]; i <= n; i++) {
            if(!used[i] && i) {
                used[i] = 1;
                for(int j = 1; j <= nrd[i]; j++) {
                    fr[elev[i][j]]++;
                }
                sol[pas] = i;
                bkt(pas + 1);
                for(int j = 1; j <= nrd[i]; j++) {
                    fr[elev[i][j]]--;
                }
                used[i] = 0;
            }
        }
    }
}

int main() {
    fin >> n >> k >> d;
    for(int i = 1; i <= n; i++) {
        fin >> nrd[i];
        for(int j = 1; j <= nrd[i]; j++) {
            fin >> elev[i][j];
        }
    }
    
    bkt(1);
    
}
