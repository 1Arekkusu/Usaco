#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string s;

int main()
{
    int n,mn,mx,i,j;
    cin>>n;
    cin>>s;
    mn = mx = 0;
    i = 0;
    while(i < n)
    {
        while(s[i] == 'F')
            i++;

        j = i + 1;
        while(j < n && s[j] == 'F')
        {
            j++;
        }
        if(j == n)
            break;

        int nrF = j - i - 1;
        if(s[i] == s[j])
        {
            int l = j-i+1;
            if(l % 2 == 0)
                mn++;
            mx += l - 1;
        }
        else
        {
            int l = j-i+1;
            if(l % 2 != 0)
            {
                mn++;
            }
            mx += l - 2;
        }
        i = j;
    }
    int start_F, end_F;
    start_F = end_F = 0;
    while(start_F < n && s[start_F] == 'F')start_F++;
    while(end_F < n && s[n - end_F - 1] == 'F')end_F++;
    if(start_F == n)
    {
        mn = 0;
        mx = n - 1;
    }
    else
    {
        mx += start_F;
        mx += end_F;
    }


    vector<int>ans;
    if(start_F == 0 && end_F == 0)
    {
        for(i = mn; i <= mx; i += 2)
            ans.push_back(i);
    }
    else
    {
        for(i = mn; i <= mx; i++)
            ans.push_back(i);
    }

    cout<<ans.size()<<'\n';
    for(i = 0; i < ans.size(); i++)
        cout<<ans[i]<<'\n';
    return 0;
}
