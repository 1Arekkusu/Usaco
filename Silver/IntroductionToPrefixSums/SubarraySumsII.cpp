#include <iostream>
#include <map>

using namespace std;

map <long long, int> sums;

int main()
{
    long long n,a,i,sum,ans,x;
    cin>>n>>x;
    sum = 0;
    ans = 0;
    sums[0] = 1;
    for(i = 1; i <= n; i++)
    {
        cin>>a;
        sum += a;
        ans += sums[sum - x];
        sums[sum]++;
    }
    cout<<ans;
    return 0;
}
