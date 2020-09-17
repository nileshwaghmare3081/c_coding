#include<stdio.h>
#include<math.h>
 
int main()
{
      int dec = 0, rem, oct;
      int count = 0;
      
      printf("Enter a Octal Number: ");
      scanf("%d", &oct); 
      
      while(oct > 0)
      {
            rem = oct % 10;
            dec = dec + rem * pow(8, count);
            printf("pow %f\n",pow(8, count));
            oct = oct / 10;
            count++;
      }
      
      printf("\nDecimal Equivalent: %d\n", dec);
      return 0;
}
