#include<stdio.h>
#define m 100000
void heapify(long arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  	int temp;
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
      //swap(arr[i], arr[largest]); 
      	temp=arr[i];
      	arr[i]=arr[largest];
      	arr[largest]=temp;
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(long arr[], int n) 
{ 
	int temp;
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  	for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        //swap(arr[0], arr[i]); 
  		temp=arr[i];
      	arr[i]=arr[0];
      	arr[0]=temp;
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
int func2(int p,long *a,int n,int c)
{
	long pos=a[0];
	int cows=1,i;
	for(i=1;i<n;i++)
	{
		if(a[i]-pos>=p)
		{
			pos=a[i];
			cows++;
		}
		if(cows==c)
			return 1;
	}
	return 0;
}
long func1(long *a,int n,int c)
{
	int l=0,h=a[n-1]-a[0],mid,max=-1;
	while(l<h)
	{
		mid=(l+h)/2;
		if(func2(mid,a,n,c))
		{
			if(mid>max)
				max=mid;
			l=mid+1;	
		}
		else
		{
			h=mid;
		}
		
	}
	return max;
}
int main()
{
	int t,n,c,i,j,k,key;
	long a[m],max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		heapSort(a,n);	
		max=func1(a,n,c);
		printf("%d",max);
		
	}
	return 0;
}
