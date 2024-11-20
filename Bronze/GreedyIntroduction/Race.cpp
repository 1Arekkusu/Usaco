#include <fstream>

using namespace std;

ifstream f("race.in");
ofstream g("race.out");

int main()
{
    int dist,n,i,a;
    int speed,dist_to_slow,pos,ans;
    f>>dist>>n;
    for(i = 1; i <= n; i++)
    {
        f>>a;
        ans = 0;
        speed = 1;
        dist_to_slow = 0;
        pos = 0;
        while(true)
        {
            pos += speed;
            ans++;
            if(pos + dist_to_slow >= dist)break;
            if(speed >= a)
            {
                dist_to_slow += speed;
                ans++;
                if(pos + dist_to_slow >= dist)break;
            }
            speed++;
        }
        g<<ans<<'\n';

    }
    return 0;
}
