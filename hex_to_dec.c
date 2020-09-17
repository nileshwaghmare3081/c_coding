#include<stdio.h>
#include<math.h>
 
int main()
{
      int dec = 0, rem, hex;
      int count = 0;
      
      printf("Enter a Hexadecimal Number: ");
      scanf("%d", &hex); 
      
      while(hex > 0)
      {
            rem = hex % 10;
            dec = dec + rem * pow(16, count);
            printf("pow %f\n",pow(16, count));
            hex = hex / 10;
            count++;
      }
      
      printf("\nDecimal Equivalent: %d\n", dec);
      return 0;
}
