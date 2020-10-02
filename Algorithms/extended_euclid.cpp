//extended euclid algorithm
// ax + by = gcd(a,b)
// so, given a & b, we can find x,y which fits this equation

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main()
{
	int a,b,x,y;
	cin>>a>>b;
	int d=gcd(a,b,x,y);
	cout<<d<<endl;
	cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<d;
	return 0;
}
