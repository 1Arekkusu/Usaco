#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream f("hoofball.in");
ofstream g("hoofball.out");

int v[101], graph[101];
int ok[101];

int main()
{
    int n,i,ans;
    f>>n;
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        f>>v[i];
    }
    sort(v + 1, v+n+1);
    graph[1] = 2;
    graph[n] = n-1;
    ok[2] = 1;
    ok[n-1] = 1;
    for(i = 2; i < n; i++)
    {
        if(v[i] - v[i-1] <= v[i+1] - v[i])
        {
            graph[i] = i-1;
            ok[i-1]++;
        }
        else
        {
            graph[i] = i+1;
            ok[i+1]++;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(ok[i] == 0)
            ans++;
        if(ok[i] == 1)
        {
            if(graph[i+1] == i && graph[i] == i+1 && ok[i+1] == 1)
                ans++;
        }
    }
    g<<ans;
    return 0;
}
