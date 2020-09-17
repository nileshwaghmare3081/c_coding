/*Program to check entered number is whether prime or not.*/
 
#include <stdio.h>
 
int main()
{
    int tally;
    int number;
    unsigned char flag=0;
 
    printf("Enter an integer number : ");
    scanf("%d",&number);
 
    for(tally=2; tally<=(number/2); tally++)
    {
        if(number%tally ==0)
        {
            flag=1;
            break;
        }
    }
     
    if(flag==0)
        printf("\n%d is a prime number.",number);
    else
        printf("\n%d is not a prime number.",number);
 
    return 0;
}
