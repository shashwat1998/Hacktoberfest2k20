//finding gcd of two nos. in both ways , recursive and iterative

//time complexity:- O(log min(a,b))


#include<bits/stdc++.h>
using namespace std;

/*
//recursive implementation
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
*/

//iterative implementation
int gcd(int a,int b)
{
	int t;
	while(b!=0)
	{
		t=a;
		a=b;
		b=t%b;
	}
	return a;
}


int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b); 
	return 0;
}
