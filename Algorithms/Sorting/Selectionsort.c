#include<stdio.h>
void selectiontionsort(int arr[],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        int min = i;
        for(j = i+1;j < n;j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }
        if(min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    selectiontionsort(arr,8);
    printf("\nArray after insertion sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}
