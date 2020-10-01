#include<stdio.h>
void shellsort(int arr[],int n)
{
    int gap,i;
    for(gap = n/2;gap > 0;gap/=2)
    {
        for (i = gap; i < n; i += 1) 
        {  
            int temp = arr[i];
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            arr[j] = temp; 
        } 
    } 

}

int main()
{
    int arr[] = {0,5,6,3,8,9,2,1},i;
    printf("Array before sorting: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    shellsort(arr,8);
    printf("\nArray after shell sort: ");
    for(i=0;i<8;i++)
        printf("%d ",arr[i]);
    return 0;
}
