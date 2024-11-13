#include <fstream>

using namespace std;

ifstream f("taming.in");
ofstream g("taming.out");

int v[101];

int main()
{
    int n,i,ans1,ans2;
    bool valid = 1;
    f>>n;
    ans1 = 0;
    ans2 = 0;
    for(i = 1; i <= n; i++)
    {
        f>>v[i];
    }
    if(v[1] > 0)valid = 0;
    v[1] = 0;
    int t = -1;
    for(i = n; i >= 1; i--)
    {
        if(t != -1 && v[i] != -1 && t != v[i])
        {
            valid = 0;
            break;
        }
        if(v[i] == -1 && t == -1)
            ans2++;
        if(v[i] != - 1 && t == -1)
        {
            t = v[i];
            ans1++; ans2++;
        }
        if(t != -1)
            t--;

    }
    if(valid)
        g<<ans1<<" "<<ans2;
    else
        g<<-1;
    return 0;
}
