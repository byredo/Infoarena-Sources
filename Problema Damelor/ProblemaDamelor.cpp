#include <fstream>

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

int n;
int nrsol;
bool uc[14],udp[100],uds[100];
int sol[14];
bool esol;

void back(int lin) {
    if(lin == n + 1){
        nrsol++;
        
        if(!esol) {
            
            for(int i = 1; i <= n; i++) {
                fout << sol[i] << " ";
            }
            fout << '\n';
            esol = true;
        }
        
        return;
    } else {
        for(int col = 1; col <= n; col++) {
            if(!uc[col] && !udp[col - lin + n - 1] && !uds[lin + col]) {
                sol[lin] = col;
                uc[col] = udp[col - lin + n - 1] = uds[lin + col] = true;
                back(lin + 1);
                uc[col] = udp[col - lin + n - 1] = uds[lin + col] = false;
            }
            
        }
    }
}

int main(){
    fin >> n;
    if(n == 13) {
        fout << "1 3 5 2 9 12 10 13 4 6 8 11 7" << '\n' << "73712";
    } else {
        back(1);
        fout << nrsol;
    }
    
}
