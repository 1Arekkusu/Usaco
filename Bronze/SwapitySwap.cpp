#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream f("swap.in");
ofstream g("swap.out");

void reverse_seg(vector<int> &v, int i, int j)
{
    while(i < j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}

int main()
{
    int n,k,a1,a2,b1,b2,i,j;
    f>>n>>k;
    f>>a1>>a2;
    f>>b1>>b2;

    vector<int> cows(n);

    for(i = 0; i < n; i++)
        cows[i] = i + 1;

    set<vector<int>> permutations{cows};
    while(true)
    {
        reverse_seg(cows, a1-1, a2-1);
        reverse_seg(cows, b1-1, b2-1);
        if(permutations.count(cows)) break;
        permutations.insert(cows);
    }

    int cycle = permutations.size();
    k = k % cycle;
    for(i = 0; i < k; i++)
    {
        reverse_seg(cows, a1-1, a2-1);
        reverse_seg(cows, b1-1, b2-1);
    }
    for(i = 0; i < n; i++)
        g<<cows[i]<<'\n';
    return 0;
}
