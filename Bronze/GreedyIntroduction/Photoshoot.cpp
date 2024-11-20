#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,ans,i;
    string s;
    cin>>n;
    cin>>s;
    ans = 0;
    for(i = n - 2; i >= 0; i -= 2)
    {
        string sub = s.substr(i, 2);
        if((sub == "GH" && ans % 2 == 0) || (sub == "HG" && ans % 2 == 1))
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
