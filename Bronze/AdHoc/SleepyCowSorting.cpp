#include <fstream>

using namespace std;

ifstream f("sleepy.in");
ofstream g("sleepy.out");

int v[101];

int main()
{
    int n,i;
    bool ok = 0;
    f>>n;
    for(i = 1; i <= n; i++)
        f>>v[i];
    for(i = n-1; i > 0; i--)
    {
        if(v[i] > v[i+1])
        {
            g<<i;
            ok = 1;
            break;
        }
    }
    if(!ok)
        g<<0;
    return 0;
}
