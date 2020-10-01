#include<stdio.h>
void insertionsort(int arr[],int n)
{
    int i,j;
    for(i=1;i <n;i++)
    {
        int temp = arr[i];
        j = i-1;
        while(j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    insertionsort(arr,8);
    printf("\nArray after insertion sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}
