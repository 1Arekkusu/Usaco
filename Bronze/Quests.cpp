#include <iostream>

using namespace std;

int a[200001],b[200001];

int main()
{
    int t,test_num,i,n,k;
    cin>>test_num;
    for(t = 1; t <= test_num; t++)
    {
        cin>>n>>k;
        for(i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        for(i = 1; i <= n; i++)
        {
            cin>>b[i];
        }
        int best = b[1];
        int total = a[1];
        int max_score = a[1] + best * (k - 1);
        for(i = 2; i <= min(n,k); i++)
        {
            best = max(best, b[i]);
            total += a[i];
            max_score = max(max_score, total + best * (k - i));
        }
        cout<<max_score<<'\n';
    }
    return 0;
}
