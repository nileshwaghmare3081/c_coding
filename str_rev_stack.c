/*String reverse using stack
 * */
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    unsigned capacity;
	char *arr;
};

struct stack *create_stack(unsigned capacity)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char *)malloc(sizeof(char)*capacity);
    return stack;
}

int is_full(struct stack *stack)
{
    return stack->top == stack->capacity-1;
}

int is_empty(struct stack *stack)
{
    return stack->top == -1;
}


void push(struct stack *stack, char item)
{
    if(is_full(stack))
        return;
    else
        stack->arr[++stack->top] = item;
}

int pop(struct stack *stack)
{
    if(is_empty(stack))
        return INT_MIN;
    else
        return stack->arr[stack->top--];
}

int peak(struct stack *stack)
{
    if(is_empty(stack))
        return INT_MIN;
    else
        return stack->arr[stack->top];
}

void reverse_string(char str[], int len)
{
    int ind;
    struct stack *stack = create_stack(len-1);

    for(ind = 0; ind<len; ind++)
        push(stack , str[ind]);

    for(ind = 0; ind<len; ind++)
        str[ind] = pop(stack);

     printf("rev string is %s\n",str);
}

int main() 
{ 
    char string[10] = "nileshwagh";
    int len = strlen(string);

    reverse_string(string, len);
    return 0;
}
