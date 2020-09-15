#include<stdio.h>

void convert(int num, int b) 
{ 
    int i=0, j, rem;
    char arr[20];

    while(num > 0)
    {
        rem = num % b;
        num = num / b;
        
        if(rem > 9 && rem < 16)
            arr[i++] = rem - 10 + 'A';
        else
            arr[i++] = rem + '0';
    }

    for(j=i-1; j>=0; j--)
    {
        printf("%c",arr[j]);
    }
    printf("\n");
}  
  
int main() 
{ 
    int dec = 20;

    convert(dec, 2);
    convert(dec, 8);
    convert(dec, 16);

    return 0; 
} 
