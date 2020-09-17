#include<stdio.h>
#include<string.h>

void selection_sort(int arr[], int len) 
{ 
    int i, j, temp, min;
   
    for(i = 0; i < len-1; i++)
    {
        min = i;
        for(j = i+1; j < len; j++)
        {    
            if(arr[min] > arr[j])
                min = j;
        }    
        
        if(i != min)
        {
            //printf("min is : %d\n",min);
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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

    selection_sort(arr, sizeof(arr)/sizeof(arr[0]));
    return 0; 
} 
