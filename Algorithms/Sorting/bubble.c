#include<stdio.h>
void bubblesort(int arr[],int n)
{
    int i,j;
    for(i = 0;i < n-1;i++)
    {
        int count = 0;
        for(j = 0;j < n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
        if(count == 0)
            break;
    }
}
int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    bubblesort(arr,8);
    printf("\nArray after bubble sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}
