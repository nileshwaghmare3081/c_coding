#include<stdio.h>
#include<string.h>

void insertion_sort(int arr[], int len) 
{ 
    int i, j, k;
   
    for(i = 1; i < len; i++)
    {
        //k is to be placed at proper location
        k = arr[i];
        for(j = i-1; j>=0 && k<arr[j]; j--)
        {    
            arr[j+1] = arr[j];
        }    
        arr[j+1] = k;
    }

    printf("sorted array is: ");
    for(int ind=0; arr[ind]!='\0';ind++)
    {
        printf("%d ",arr[ind]);
    }
    printf("\n");
}  
  
int main() 
{ 
    int arr[] = {1,2,12,4,18,45,10};
    
    printf("given array is: ");
    for(int ind=0; arr[ind]!='\0';ind++)
    {
        printf("%d ",arr[ind]);
    }
    printf("\n");

    insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
    return 0; 
} 
