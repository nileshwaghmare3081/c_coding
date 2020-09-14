/*Implement two stacks using a single arr and check for overflow and underflow
 */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE 10
static int top1 = -1;
static int top2 = SIZE;
static int arr[SIZE];

void push_stack1(int item)
{
    if(top1 < top2-1)
    {    
        arr[++top1] = item;
    }
    else
        printf("stack1 is full\n");
}

void push_stack2(int item)
{
    if(top1 < top2-1)
    {    
        arr[--top2] = item;
    }
    else
        printf("stack2 is full\n");
}

int pop_stack1()
{
    if(top1 >= 0 )
        printf("stack1 : popped value is %d\n",arr[top1--]);
    else
        printf("stack1 : is empty\n");       
}

int pop_stack2()
{
    if(top2 < SIZE )
        printf("stack2 : popped value is %d\n",arr[top2++]);
    else
        printf("stack2 : is empty\n");       
}

void print_stack2()
{
    int ind;
    printf("printing stack2 : ");       
    
    for(ind = top2; ind < SIZE; ++ind)
        printf("%d ",arr[ind]);

    printf("\n");
}

void print_stack1()
{
    int ind;
    printf("printing stack1 : ");       

    for(ind = top1; ind >= 0; --ind)
        printf("%d ",arr[ind]);       
    
    printf("\n");
}

int main() 
{ 
    int ind, num_of_ele;

    printf("We can push total of %d values\n", SIZE);

    for(ind = 1; ind<=6; ind++)
        push_stack1(ind);
    
    for(ind = 1; ind<=4; ind++)
        push_stack2(ind);

    print_stack1();
    print_stack2();

    num_of_ele = top1 + 1;

    while(num_of_ele)
    {
        pop_stack1();
        --num_of_ele;
    }

    return 0;
}
