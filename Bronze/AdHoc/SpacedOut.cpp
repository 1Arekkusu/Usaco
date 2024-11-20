#include <iostream>

using namespace std;

int a[1001][1001];

int sum[2];

int main()
{
    int n,i,j;
    int ans1 = 0, ans2 = 0;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        sum[0] = sum[1] = 0;
        for(j = 1; j <= n; j++)
        {

            cin>>a[i][j];
            sum[j%2] += a[i][j];
        }
        ans1 += max(sum[0],sum[1]);
    }
    for(j = 1; j <= n; j++)
    {
        sum[0] = sum[1] = 0;
        for(i = 1; i <= n; i++)
        {
            sum[i%2] += a[i][j];
        }
        ans2 += max(sum[0], sum[1]);
    }
    cout<<max(ans1,ans2);
    return 0;
}
