#include <fstream>

using namespace std;

ifstream f("herding.in");
ofstream g("herding.out");

int main()
{
    int a,b,c;
    f>>a>>b>>c;
    if(a > c)
        swap(a, c);
    if(b > c)
        swap(b,c);
    if(a > b)
        swap(a,b);
    if(a == b - 1 && b == c - 1)
        g<<0<<'\n'<<0;
    else
    {
        if(b - a == 2 || c - b == 2)
        {
            g<<1<<'\n';
        }
        else
        {
            g<<2<<'\n';
        }
        g<<max(b-a-1, c-b-1);
    }
    return 0;
}
