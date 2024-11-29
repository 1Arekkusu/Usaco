#include <fstream>

using namespace std;

ifstream f("bcount.in");
ofstream g("bcount.out");

int v[100001][4];

int main()
{
    int n,q,i,a,b,j;
    f>>n>>q;
    for(i = 1; i <= n; i++)
    {
        f>>a;
        v[i][1] = v[i-1][1];
        v[i][2] = v[i-1][2];
        v[i][3] = v[i-1][3];
        v[i][a]++;
    }
    for(i = 1; i <= q; i++)
    {
        f>>b>>a;
        g<<v[a][1] - v[b-1][1]<<" ";
        g<<v[a][2] - v[b-1][2]<<" ";
        g<<v[a][3] - v[b-1][3];
        g<<'\n';
    }
    return 0;
}
