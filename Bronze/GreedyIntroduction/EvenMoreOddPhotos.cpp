#include <iostream>

using namespace std;

int ans;

int solve(int odd, int even)
{
    int diff = odd - even;
    if(diff == 0)
        return even + odd;
    if(diff == 1)
        return even + odd - 2;
    if(diff == 2)
        return even + odd - 1;

    odd -= 2;
    even += 1;

    return solve(odd, even);
}

int main()
{
    int n,a,odd,even,i;
    odd = even = 0;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>a;
        if(a%2)
            odd++;
        else
            even++;
    }
    if(odd == even)
        ans = n;
    else
    {
        if(even > odd)
            ans = 2 * odd + 1;
        else
        {
            ans = solve(odd, even);
        }
    }
    cout<<ans;
    return 0;
}
