#include<stdio.h>

int atoi(char *str) 
{ 
    int res = 0, sign = 1, ind = 0;

    if(*str == '\0')
        return 0;

    if(str[0] == '-')
    {    
        sign = -1;
        ind++;
    }
    
    for(; str[ind]!='\0'; ind++)
    {
        if(str[ind] <= '0' || str[ind] >= '9' )
            return 0;
        res = res * 10 + str[ind] - '0';
    }
    
    return res * sign;
}  
  
int main() 
{ 
    char str[] = "-12";
    printf("ascii to integer %d\n",atoi(str));
    return 0; 
} 
