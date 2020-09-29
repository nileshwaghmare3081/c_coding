/*dynamically allocate a 2D array*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() 
{ 
    int i, j, rows, cols;
    int **a;
    
    printf("Enter number of rows and cols : ");
    scanf("%d%d",&rows, &cols);

    printf("Allocate a one dimentional array of int pointers :\n");
    a = (int **)malloc(rows * sizeof(int *));

    printf("Allocate a one dimentional array of integer for each row pointer :\n");
    for(i = 0; i<rows; i++)
        a[i] = (int *)malloc(cols * sizeof(int));
    
    for(i=0; i < rows; i++)
    {
        for(j=0; j < cols; j++)
        {    
            printf("Enter a[%d][%d] :",i ,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is :\n");

    for(i=0; i < rows; i++)
    {    
        for(j=0; j < cols; j++)
        {    
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    
    for(i=0; i < rows; i++)
        free(a[i]);
    
    free(a);

    return 0; 
} 
