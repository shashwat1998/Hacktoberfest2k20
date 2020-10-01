#include<stdio.h>

int partition(int arr[],int l,int u)
{
    int pivot = arr[l];
    int i = u+1,j,temp;
    for(j=u;j>l;j--)
    {
        if(arr[j]>=pivot)
        {
            i--;
            temp =  arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i-1];
    arr[i-1] = arr[j];
    arr[j] =temp;
    return i-1;
}

void quicksort(int arr[],int l,int u)
{
    if(l < u)
    {
        int k = partition(arr,l,u);
        quicksort(arr,l,k-1);
        quicksort(arr,k+1,u);
    }
}

int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    quicksort(arr,0,size-1);
    printf("\nArray after quicksort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}