#include <fstream>

using namespace std;

ifstream f("square.in");
ofstream g("square.out");

struct punct{
    int x1,x2,y1,y2;
}pct[3];

int main()
{
    int l,L;
    f>>pct[1].x1>>pct[1].y1>>pct[1].x2>>pct[1].y2;
    f>>pct[2].x1>>pct[2].y1>>pct[2].x2>>pct[2].y2;
    l = max(pct[1].x2, pct[2].x2) - min(pct[1].x1, pct[2].x1);
    L = max(pct[1].y2, pct[2].y2) - min(pct[1].y1, pct[2].y1);
    l = max(L,l);
    g<<l * l;
    return 0;
}
