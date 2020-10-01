#include<stdio.h>

void heapify(int arr[],int n,int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;

		heapify(arr,n,largest);
	}
}

void heapsort(int arr[],int n)
{
	int i,temp;
	for(i = n/2 - 1;i>=0;i--)
		heapify(arr,n,i);
	for(i = n-1;i >= 0;i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		
		heapify(arr,i,0);
	}
}

int main()
{
	int arr[] = {0,5,6,3,8,9,2,1},i;
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    heapsort(arr,8);
    printf("\nArray after heap sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
	return 0;
}