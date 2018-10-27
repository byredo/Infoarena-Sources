#include <fstream>

using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int n;
int nrsub;

int main() {
    fin >> n;
    
    nrsub = 1 << n;  ///numarul de submultimi este 2^n, iar 1 << n este al n + 1 -lea bit (daca luam 2^0 in considerare), ceea ce inseamna 2^n.
    
    for(int i = 1; i < nrsub; i++)  //mergem pana la 2^n - 1, acela fiind numarul de submultimi fara submultimea vida
    {
        for(int j = 1; j <= n; j++)
            if(i & (1 << (j - 1)))   //i reprezentarea binara a lui i
                fout << j << " ";   // i << (j - 1) este al j-lea bit (vezi 1 << n), -1 este pentru ca numaram si bitul 0 aici, avand si nr imp.
                                    //i & (1 << (j - 1)) inseamna : daca pe pozitia j - 1 a reprezentarii binare a numarului i se afla 1 afiseaza...
        fout << '\n';
    }
    
    
    
}
