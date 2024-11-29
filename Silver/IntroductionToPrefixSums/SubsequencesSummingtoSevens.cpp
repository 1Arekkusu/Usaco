#include <fstream>
#define MOD 7

using namespace std;

ifstream f("div7.in");
ofstream g("div7.out");

int first[7];

int main()
{
    int n,i,a,sum,ans;
    f>>n;
    sum = 0;
    ans = 0;
    first[0] = 0;
    for(i = 1; i <= n; i++)
    {
        f>>a;
        sum = (sum + a) % MOD;
        if(first[sum] == 0)
            first[sum] = i;
        else
        {
            ans = max(ans, i - first[sum]);
        }
    }
    g<<ans;
    return 0;
}
