#include <fstream>
#include <string>
#include <set>
#include <map>


using namespace std;

ifstream f("family.in");
ofstream g("family.out");

int t[105],nivel[105];
set<string> names;
set<int> fiu[105];
map<string, int> mp;

void bfs(int nod, int depth)
{
    nivel[nod] = depth;
    for(set<int>::iterator it = fiu[nod].begin(); it != fiu[nod].end(); it++)
    {
        bfs(*it, depth+1);
    }
}

int findCommonAncestor(int a, int b)
{
    while(nivel[a] < nivel[b])
        b = t[b];
    while(nivel[b] < nivel[a])
        a = t[a];
    while(a != b)
    {
        a = t[a];
        b = t[b];
        if(nivel[a] == 0)
            return 0;
    }
    return a;
}

int main()
{
    int n,i,members,common;
    string a,b,s1,s2;
    f>>n>>a>>b;
    members = 2;
    mp[a] = 1;
    mp[b] = 2;
    names.insert(a); names.insert(b);
    for(i = 1; i <= n; i++)
    {
        f>>s1>>s2;
        if(!names.count(s1))
        {
            mp[s1] = ++members;
            names.insert(s1);
        }
        if(!names.count(s2))
        {
            mp[s2] = ++members;
            names.insert(s2);
        }
        t[mp[s2]] = mp[s1];
        fiu[mp[s1]].insert(mp[s2]);
    }
    for(i = 1; i <= members; i++)
    {
        if(t[i] == 0)
        {
            bfs(i, 1);
        }
    }
    common = findCommonAncestor(1, 2);
    if(common == 0)
        g<<"NOT RELATED";
    else
    {
        if(common == 1 || common == 2)
        {
            if(common == 1)
            {
                g<<a<<" is the ";
                for(i = 3; i <= nivel[2] - nivel[1]; i++)
                    g<<"great-";
                if(nivel[2] - nivel[1] > 1)g<<"grand-";
                g<<"mother of "<<b;
            }
            else
            {
                g<<b<<" is the ";
                for(i = 3; i <= nivel[1] - nivel[2]; i++)
                    g<<"great-";
                if(nivel[1] - nivel[2] > 1)g<<"grand-";
                g<<"mother of "<<a;
            }
        }
        else
        {   if(nivel[1] - nivel[common] == 1 && nivel[2] - nivel[common] == 1)
                g<<"SIBLINGS";
            else
            {
                if(nivel[1] - nivel[common] == 1)
                {
                    g<<a<<" is the ";
                    for(i = 3; i <= nivel[2] - nivel[common]; i++)
                        g<<"great-";
                    g<<"aunt of "<<b;
                }
                else if(nivel[2] - nivel[common] == 1)
                {
                    g<<b<<" is the ";
                    for(i = 3; i <= nivel[1] - nivel[common]; i++)
                        g<<"great-";
                    g<<"aunt of "<<a;
                }
                else
                {
                    g<<"COUSINS";
                }
            }
        }
    }
    return 0;
}
