#define DM 2000000
#include <bitset>
#include <iostream>
#include <fstream>
using namespace std;
ifstream in("ciur.in");
ofstream out("ciur.out");
bitset <DM> bs;
int v[DM];
int n,contor;

int main()
{
    in>>n;
    for(int i=2;i<=n;++i)
    {
        if(bs[i]==0)
        {
            ++contor;
            for(int j=i*2;j<=n;j+=i)
                bs[j]=1;
        }
    }
    
    out<<contor;
    return 0;
}
