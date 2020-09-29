/*dynamically allocate a 2D array using array of pointers*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() 
{ 
    int i, j ,cols;
    int *a[3];
    
    printf("Enter number of cols : ");
    scanf(" %d",&cols);

    for(i=0; i < cols; i++)
        a[i] = (int *)malloc(cols * sizeof(int));

    for(i=0; i < 3; i++)
    {
        for(j=0; j < cols; j++)
        {    
            printf("Enter a[%d][%d] :",i ,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is :\n");

    for(i=0; i < 3; i++)
    {    
        for(j=0; j < cols; j++)
        {    
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    
    for(i=0; i < 3; i++)
        free(a[i]);
    return 0; 
} 
