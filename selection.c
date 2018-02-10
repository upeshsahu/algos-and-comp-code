#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx=j;
        swap(&arr[min_idx], &arr[i]);
    }
}
 
 
int main()
{  int n;
   printf("Enter the Size Of Array\n");
   scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);


    selectionSort(arr, n);
    printf("Sorted array: \n");
    
    
    for (int i=0; i <n; i++)
        printf("%d ", arr[i]);
  

    return 0;
}
