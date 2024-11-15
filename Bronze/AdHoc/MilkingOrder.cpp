#include <fstream>

using namespace std;

ifstream f("milkorder.in");
ofstream g("milkorder.out");

int ord[101],v[101],cow_to_pos[101],n,m,k;

int check()
{
    int i;
    int ord2[101];
    for(i = 1; i <= n; i++)
    {
        cow_to_pos[i] = 0;
        ord2[i] = ord[i];
    }

    for(i = 1; i <= n; i++)
    {
        if(ord2[i] != 0)cow_to_pos[ord2[i]] = i;
    }

    int h_idx = 1;
    for(i = 1; i <= n && h_idx <= m; i++)
    {
        if(cow_to_pos[v[h_idx]] != 0)
        {
            if(i > cow_to_pos[v[h_idx]]) return 0;

            i = cow_to_pos[v[h_idx]];
            h_idx++;
        }
        else
        {
            while(i <= n && ord2[i] != 0)
                i++;

            if(i > n)return 0;

            ord2[i] = v[h_idx];
            cow_to_pos[v[h_idx]] = i;
            h_idx++;
        }
    }

    return 1;
}

int main()
{
    int i,a,b;
    f>>n>>m>>k;
    for(i = 1; i <= m; i++)
    {
        f>>v[i];
    }
    for(i = 1; i <= k; i++)
    {
        f>>a>>b;
        ord[b] = a;
        if(a == 1)
        {
            g<<b;
            return 0;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(ord[i] == 0)
        {
            ord[i] = 1;
            if(check())
            {
                g<<i;
                break;
            }
            ord[i] = 0;
        }
    }
    return 0;
}
