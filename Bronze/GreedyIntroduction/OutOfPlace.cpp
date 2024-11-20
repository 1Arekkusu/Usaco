#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("outofplace.in");
ofstream g("outofplace.out");

int c[101],v[101];

int main()
{
    int n,i;
    f>>n;
    for(i = 1; i <= n; i++)
    {
        f>>v[i];
        c[i] = v[i];
    }
    sort(v + 1, v + n + 1);
    int ans = 0;
    for(i = 1; i <= n; i++)
    {
        if(c[i] != v[i])
        {
            ans++;
        }
    }
    g<<max(0,ans - 1);
    return 0;
}
