#include <fstream>

using namespace std;

ifstream f("art.in");
ofstream g("art.out");

int a[11][11];
bool ok[11];
int n;

bool isOnTop(int c1, int c2)
{
    int i,j;
    int top,bottom,left,right;
    bottom = right = 0;
    top = left = 20;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(a[i][j] == c2)
            {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }
    for(i = top; i <= bottom; i++)
    {
        for(j = left; j <= right; j++)
        {
            if(a[i][j] == c1) return true;
        }
    }
    return false;
}

int main()
{
    int i,j,ans;
    char c;
    bool pos;
    ans = 0;
    f>>n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            f>>c;
            a[i][j] = c - '0';
            ok[a[i][j]] = true;
        }
    }
    for(i = 1; i <= 9; i++)
    {
        if(ok[i])
        {
            pos = true;
            for(j = 1; j <= 9; j++)
            {
                if(i != j && ok[j] && isOnTop(i, j))
                {
                    pos = false;
                }
            }
            if(pos)ans++;
        }
    }
    g<<ans;
    return 0;
}
