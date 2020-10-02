//euler's totient function (aka, phi-function)
//		IT TELLS THE NO. OF NOS. FROM 1 TO N THAT ARE COPRIME TO N
//if a and b are relatively prime,  phi(ab)=phi(a)*phi(b)
//if a is prime, phi(a)=a-1
//phi(pow(p,k))= pow(p,k) - pow(p,k-1)	,where k>=1
#include<bits/stdc++.h>
using namespace std;


// an implementation using factorization in O(sqrt(n)) 
int phi(int n)
{
	int result=n,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n/=i;
			result-=result/i;	
		}
	}
	if (n > 1)
        result -= result / n;
    return result;
}

//finding totient from 1 to n
//divisor sum property:- sum of values of phi-function of all the divisors of a no. is the no. itself
//value of phi-function of n is n-1 if n is prime
//time complexity: O(nlogn)
void phi_1_to_n(int n,vector<int> &phi) 
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}



int main()
{
	int n;
	cin>>n;
	cout<<phi(n)<<endl;
	vector<int> phi(n + 1);
	phi_1_to_n(n,phi);
	for (int i = 0; i <= n; i++)
		cout<<phi[i]<<" ";
	return 0;
}
