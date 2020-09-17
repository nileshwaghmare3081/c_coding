// C program to demonstrate deep copy
// Array supports deep copy while pointers does not
# include <stdio.h> 
# include <string.h> 
# include <stdlib.h> 
  
struct test 
{ 
  char str[20]; 
  //char *str;
}; 
  
int main() 
{ 
  struct test st1, st2; 
  //st1.str = (char *)malloc(sizeof(char) * 20); 
  
  strcpy(st1.str, "GeeksforGeeks"); 
  
  st2 = st1; 
  
  // We add extra statements to do deep copy 
  //st2.str = (char *)malloc(sizeof(char) * 20); 
  //strcpy(st2.str, st1.str); 
  
  st1.str[0] = 'X'; 
  st1.str[1] = 'Y'; 
  
  /* Since copy was deep, both strings are different */
  printf("st1's str = %s\n", st1.str);  
  printf("st2's str = %s\n", st2.str); 
  
  return 0; 
} 

