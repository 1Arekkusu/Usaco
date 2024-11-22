#include <fstream>
#define MAX_POS 2000

using namespace std;

ifstream f("billboard.in");
ofstream g("billboard.out");

struct punct
{
    int x1,x2,y1,y2;
}p[3];

bool isCornerCovered(int x,int y, int x1, int x2, int y1, int y2)
{
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int main()
{
    int i,ovX,ovY,A,corners = 0;
    for(i = 1; i <= 2; i++)
    {
        f>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
        p[i].x1 += MAX_POS / 2;
        p[i].x2 += MAX_POS / 2;
        p[i].y1 += MAX_POS / 2;
        p[i].y2 += MAX_POS / 2;
    }
    ovX = min(p[1].x2, p[2].x2) - max(p[1].x1, p[2].x1);
    ovY = min(p[1].y2, p[2].y2) - max(p[1].y1, p[2].y1);
    if(ovX < 0)ovX = -ovX;
    if(ovY < 0)ovY = -ovY;
    A = (p[1].x2 - p[1].x1)*(p[1].y2 - p[1].y1);
    corners += isCornerCovered(p[1].x1, p[1].y1, p[2].x1, p[2].x2, p[2].y1, p[2].y2);
    corners += isCornerCovered(p[1].x1, p[1].y2, p[2].x1, p[2].x2, p[2].y1, p[2].y2);
    corners += isCornerCovered(p[1].x2, p[1].y1, p[2].x1, p[2].x2, p[2].y1, p[2].y2);
    corners += isCornerCovered(p[1].x2, p[1].y2, p[2].x1, p[2].x2, p[2].y1, p[2].y2);
    if(corners < 2)
        g<<A;
    else
    {
        g<<A - ovX * ovY;
    }
    return 0;
}
