//fibonacci nos. using 2d-matrix (matrix exponentiation)
//time complexity :- O(log n)
//0,1,1,2,3,5,8.....            and 0 is at zeroth index

/*
Some properties of Fibonacci nos.:- 
-->  F={{1,1},
        {1,0}}
     F^n = {{F(n+1) , F(n)} , 
            {F(n) , F(n-1) }}      
     where,
        F^n is F to the power n
        F(k) is k-th fibonacci no.

--> Cassini's identity:-
      F(n-1) F(n+1) - pow(F(n),2)= pow(-1,n)        

--> Addition Rule:-
      F(n+k)= F(k)F(n+1) + F(k-1)F(n)

      when k=n,  F(2n) = F(n) [ F(n+1) + F(n-1) ]
--> GCD identity:-
      GCD(F(m),F(n)) = F(GCD(m,n))
      
*/
#include<bits/stdc++.h>
using namespace std;

void multiply(int f[2][2],int m[2][2])
{
	int a,b,c,d;
	a=f[0][0]*m[0][0] + f[0][1]*m[1][0];
	b=f[0][0]*m[0][1] + f[0][1]*m[1][1];
	c=f[1][0]*m[0][0] + f[1][1]*m[1][0];
	d=f[1][0]*m[0][1] + f[1][1]*m[1][1];
	
	f[0][0]=a;
	f[0][1]=b;
	f[1][0]=c;
	f[1][1]=d;
}


void pow(int f[2][2],int n)
{
	if(n==0||n==1)
		return;
	int m[2][2]={{1,1},{1,0}};	
	pow(f,n/2);
	multiply(f,f);
	
	if(n%2!=0)
		multiply(f,m);
}


int main()
{
	int n,a,b,c;
	int f[2][2]={{1,1},{1,0}};
	cin>>n;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	pow(f,n-1);
	cout<<f[0][0];
	return 0;
}
