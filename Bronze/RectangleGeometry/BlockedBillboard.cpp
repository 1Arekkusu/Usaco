#include <fstream>

using namespace std;

ifstream f("billboard.in");
ofstream g("billboard.out");

const int MAX_POS = 2000;
int x1[4],x2[4],y1[4],y2[4];

int main()
{
    int A,ov1,ov2,xov,yov,i;
    int ans = 0;
    f>>x1[1]>>y1[1]>>x2[1]>>y2[1];
    f>>x1[2]>>y1[2]>>x2[2]>>y2[2];
    f>>x1[3]>>y1[3]>>x2[3]>>y2[3];
    for(i = 1; i <= 3; i++)
    {
        x1[i] += MAX_POS / 2;
        x2[i] += MAX_POS / 2;
        y1[i] += MAX_POS / 2;
        y2[i] += MAX_POS / 2;
    }
    for(i = 1; i <= 2; i++)
    {
        A = (x2[i] - x1[i]) * (y2[i] - y1[i]);
        xov = max(0, min(x2[i], x2[3]) - max(x1[i], x1[3]));
        yov = max(0, min(y2[i], y2[3]) - max(y1[i], y1[3]));
        ans += (A - xov*yov);
    }
    g<<ans;
    return 0;
}
