#include<stdio.h>

void swap(int* a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int l,int r)
{
	int v= arr[l];
	int i=l,j=r+1;
	do{
		do{
			i++;
		}while(i<=r&&arr[i]<v);

		do{
			j--;
		}while(arr[j]>v);
		if(i<j)
		{
			swap(&arr[i],&arr[j]);
		}
	}while(i<j);
	arr[l]=arr[j];
	arr[j]=v;
	return j;
}

void quicksort(int arr[],int l,int r)
{
	if(l>=r) return;
	int j= partition(arr,l,r);
	quicksort(arr,l,j-1);
	quicksort(arr,j+1,r);
}

int check(int arr[],int i,int n)
{
	if(i==0&&arr[i+1]>=arr[i])
		return 1;
	if(i==n-1&&arr[i-1]<=arr[i])
		return 1;
	if(arr[i]>=arr[i-1]&&arr[i]<=arr[i+1])
		return 1;
	return 0;
}

void cook(int arr[],int n)
{
	if(n==1) return;
	int ok[n];
	int nok[n];
	int k1=0;
	int k2=0;
	for(int i=0;i<n;i++)
	{
		if(check(arr,i,n))
			ok[k1++]=arr[i];
		else
			nok[k2++]=arr[i];
	}
	quicksort(ok,0,k1-1);
	quicksort(nok,0,k2-1);
	int i=0,j=0,k=0;
	while(i<k1&&j<k2)
	{
		if(ok[i]<nok[j])
		{
			arr[k++]=ok[i++];
		}
		else
		{
			arr[k++]=nok[j++];
		}
	}
	while(i<k1)
		arr[k++]=ok[i++];
	while(j<k2)
		arr[k++]=nok[j++];


}

int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    cook(arr,8);
    printf("\nArray after Cook kim sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}