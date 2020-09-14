#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct stack
{
    int top;
    unsigned capacity;
	int *arr;
};

struct stack *create_stack(unsigned capacity)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int)*capacity);
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


void push(struct stack *stack, int item)
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


int main() 
{ 
    struct stack *stack = create_stack(5);
    push(stack, 5);
    push(stack, 2);
    push(stack, 3);
    push(stack, 8);
    printf("popped from stack %d \n",pop(stack));
    printf("top item from stack %d \n",peak(stack));
    return 0;
}
