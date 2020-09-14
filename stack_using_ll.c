#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct stacknode
{
    int data;
    struct stacknode *next;
};

struct stacknode *newnode(int data)
{
    struct stacknode *stacknode = (struct stacknode *)malloc(sizeof(struct stacknode));
    stacknode->data = data;
    stacknode->next = NULL;
    return stacknode;
}

int is_empty(struct stacknode *root)
{
    return !root;
}

void push(struct stacknode **root, int data)
{
    struct stacknode *stacknode = newnode(data);
    stacknode->next = *root;
    *root = stacknode;
    printf("pushed data %d\n",data);
}

int pop(struct stacknode **root)
{
    if(is_empty(*root))
        return INT_MIN;

    struct stacknode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;

    free(temp);
    return popped;
}

int peak(struct stacknode *root)
{
    if(is_empty(root))
        return INT_MIN;
    
    return root->data;
}

int main() 
{ 
    struct stacknode *root = NULL;
    push(&root, 5);
    push(&root, 7);
    push(&root, 9);
    push(&root, 1);
    printf("popped from stack %d \n",pop(&root));
    printf("top item from stack %d \n",peak(root));
    return 0;
}
