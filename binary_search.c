#include<stdio.h>
#include<string.h>

int binary_search(int arr[], int size, int item) 
{ 
    int res = 0, ind = 0, low = 0, up = size-1;
    int mid;

    while(low <= up)
    {
        mid = (low + up)/2;
        
        //printf("mid is %d low %d up %d\n", mid, low, up);
        
        if(arr[mid] < item)
            low = mid + 1;
        else if(arr[mid] > item)
            up = mid - 1;
        else
            return mid + 1;
    }
    return -1;
}  
  
int main() 
{ 
    int arr[] = {1,2,3,4,18,45,100};
    
    printf("given array is: ");
    for(int ind=0; arr[ind]!='\0';ind++)
    {
        printf("%d ",arr[ind]);
    }
    printf("\n");

    int index = binary_search(arr, sizeof(arr)/sizeof(arr[0]), 45);
    printf("requested item is at %dth index\n",index);
    
    return 0; 
} 
