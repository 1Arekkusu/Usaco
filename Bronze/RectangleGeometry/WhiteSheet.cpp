#include <iostream>

using namespace std;

struct pct{
    long long int x1,x2,y1,y2;
};

pct cut(pct A, pct B)
{
    if(A.x1 >= B.x1 && B.x2 >= A.x1 && B.y1 <= A.y1 && B.y2 >= A.y2)
    {
        A.x1 = B.x2;
        A.x2 = max(A.x2, B.x2);
    }
    if (A.x2 >= B.x1 && B.x2 >= A.x2 && B.y1 <= A.y1 && B.y2 >= A.y2) {
		A.x2 = B.x1;
		A.x1 = min(A.x1, B.x1);
	}

	if (A.y1 >= B.y1 && B.y2 >= A.y1 && B.x1 <= A.x1 && B.x2 >= A.x2) {
		A.y1 = B.y2;
		A.y2 = max(A.y2, B.y2);
	}

	if (A.y2 >= B.y1 && B.y2 >= A.y2 && B.x1 <= A.x1 && B.x2 >= A.x2) {
		A.y2 = B.y1;
		A.y1 = min(A.y1, B.y1);
	}
	return A;
}

int main()
{
    pct A,B,C;
    cin>>A.x1>>A.y1>>A.x2>>A.y2;
    cin>>B.x1>>B.y1>>B.x2>>B.y2;
    cin>>C.x1>>C.y1>>C.x2>>C.y2;

    A = cut(A,B);
    A = cut(A,C);
    if((A.x2 - A.x1) * (A.y2 - A.y1))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
