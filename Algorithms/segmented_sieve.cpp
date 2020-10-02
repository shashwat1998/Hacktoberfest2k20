//segmented sieve
//Time complexity of sieve & segmented sieve :- O(n log (log n))

#include<bits/stdc++.h>
using namespace std;

void sieve(vector<int> &primes)
{
	int i,j,arr[11];
	for(i=2;i<11;i++)
		arr[i]=1;
		
	primes.push_back(2);	
	for(i=3;i*i<=10;i+=2)		
		for(j=i*i;j<=10;j+=i)
			arr[j]=0;
	
	for(i=3;i<11;i+=2)
		if(arr[i])		
			primes.push_back(i);
}

vector<int> seg_sieve(int l,int r,vector<int> prime)
{
	int i,j,base;
	vector<int> arr(r-l+1);
	for(i=0;i<r-l+1;i++)
		arr[i]=1;
	
	for(i=0;prime[i]*prime[i]<=r;i++)		
	{
		base=(l/prime[i])*prime[i];
		if(base<l)
			base+=prime[i];
		for(j=base;j<=r;j+=prime[i])
			arr[j-l]=0;
		if(base==prime[i])	
			arr[base-l]=1;
	}
	
	return arr;
}

int main()
{
	int i,n,l,r;
	cin>>l>>r;
	vector<int> primes;
	sieve(primes);
	 
	if(l==0 || l==1)
		l=2; 
	vector<int> ans=seg_sieve(l,r,primes);
	
	for(i=0;i<ans.size();i++)
		if(ans[i])
			cout<<i+l<<" ";
	
	return 0;
}
