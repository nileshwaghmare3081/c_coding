#include<stdio.h>
#include<string.h>

void bubble_sort(int arr[], int len) 
{ 
    int i, j, temp, min;
    int xchanges;

    for(i = 0; i < len-1; i++)
    {
        xchanges = 0;
        for(j = 0; j < len-1-i; j++)
        {    
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                xchanges++;
            }
        }    
        if(xchanges == 0)
            break;
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

    bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
    return 0; 
} 
