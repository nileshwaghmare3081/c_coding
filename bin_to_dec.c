#include<stdio.h>
#include<math.h>
 
int main()
{
      int dec = 0, rem, bin;
      int count = 0;
      
      printf("Enter a Binary Number: ");
      scanf("%d", &bin); 
      
      while(bin > 0)
      {
            rem = bin % 10;
            dec = dec + rem * pow(2, count);
            printf("pow %f\n",pow(2, count));
            bin = bin / 10;
            count++;
      }
      
      printf("\nDecimal Equivalent: %d\n", dec);
      return 0;
}
