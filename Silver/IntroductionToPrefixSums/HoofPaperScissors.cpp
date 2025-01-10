#include <fstream>

using namespace std;

ifstream f("hps.in");
ofstream g("hps.out");

int v[100001][4];

int main()
{
    int n,i,a,b,ans;
    char c;
    f>>n;
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        v[i][1] = v[i-1][1];
        v[i][2] = v[i-1][2];
        v[i][3] = v[i-1][3];
        f>>c;
        if(c == 'P')
            v[i][1]++;
        if(c == 'H')
            v[i][2]++;
        if(c == 'S')
            v[i][3]++;
    }
    for(i = 1; i <= n; i++)
    {
        a = max(v[i][1], max(v[i][2], v[i][3]));
        b = max(v[n][1] - v[i][1], max(v[n][2] - v[i][2], v[n][3] - v[i][3]));
        ans = max(ans, a + b);
    }
    g<<ans;
    return 0;
}
