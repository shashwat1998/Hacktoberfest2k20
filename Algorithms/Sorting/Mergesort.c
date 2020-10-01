#include<stdio.h>

void merge(int arr[],int l,int m,int h)
{
    int i,j;
    int n1,n2;
    n1 = m - l+1;
    n2 = h - m;
    int l1[n1],l2[n2];
    for(i = 0;i < n1;i++)
        l1[i] = arr[i+l];
    for(i = 0;i < n2;i++)
        l2[i] = arr[i+m+1];
    i=0;
    j=0;
    int k = l;
    while(i < n1 && j < n2)
    {
        if(l1[i] <= l2[j])
        {
            arr[k] = l1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = l2[j];
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid = l + (h-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    mergesort(arr,0,size - 1);
    printf("\nArray after insertion sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}
