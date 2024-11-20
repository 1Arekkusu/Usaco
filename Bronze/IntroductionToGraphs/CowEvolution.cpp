#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

ifstream f("evolution.in");
ofstream g("evolution.out");

set<string> all_genes;
vector<string> cows[25];

int main()
{
    int n,i,nr,j,k;
    f>>n;
    for(i = 1; i <= n; i++)
    {
        f>>nr;
        for(j = 1; j <= nr; j++)
        {
            string s;
            f>>s;
            all_genes.insert(s);
            cows[i].push_back(s);
        }
    }

    vector<string> genes(all_genes.begin(), all_genes.end());

    for(i = 0; i < all_genes.size(); i++)
    {
        for(j = i + 1; j < all_genes.size(); j++)
        {
            bool a,b,ab;
            a = b = ab = false;
            for(k = 1; k <= n; k++)
            {
                bool has_a = count(cows[k].begin(), cows[k].end(), genes[i]);
                bool has_b = count(cows[k].begin(), cows[k].end(), genes[j]);

                if(has_a && has_b)
                    ab = true;
                else if(has_a)
                    a = true;
                else if(has_b)
                    b = true;
            }
            if(a && b && ab)
            {
                g<<"no";
                return 0;
            }
        }
    }
    g<<"yes";
    return 0;
}
