/*
 *   2   * Author : Nilesh Waghmare <nileshwaghmare3081@gmail.com>
 *     3   */

// C program to Convert a Singly Linked 
// List to XOR Linked List 
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node { 
    int data; 
    struct node* next; 
}; 
  
// Utility function to create new node 
struct node* newnode(int data) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data; 
    temp->next = NULL;                     
    return temp; 
} 

// Print singly linked list before conversion 
void print(struct node* start) 
{
    struct node *temp = start;
    while(temp) { 
        // print current node 
        printf("%d ",temp->data); 
        temp = temp->next; 
    } 
    printf("\n");  
}

struct node *XOR(struct node *prev, struct node *next)
{
   return (struct node *)((uintptr_t)prev ^ (uintptr_t)next);    
}

void convert(struct node *start)
{
    struct node *curr = start; 
    struct node *prev = NULL;
    struct node *next = start->next;

    while(curr)
    {
        next = curr->next;
        curr->next = XOR(prev,next);
        prev = curr;
        curr = next;
    }
}

void printXOR(struct node *start)
{
    struct node *curr = start;
    struct node *prev = NULL;
    struct node *temp, *back_c, *back_p;
    
    while(curr)
    {
        back_c = curr;
        back_p = prev;
        
        printf("%d ",curr->data);
        temp = curr;
        curr = XOR(prev, curr->next);
        prev = temp;
    }    
    printf("\n");  
    printf("print in reverse order\n");  

    while(back_c)
    {
        printf("%d ",back_c->data);
        temp = back_c;
        back_c = XOR(back_p, back_c);
        back_p = temp;
    }     

}

struct node *insert(struct node *start, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    /* Since new node is being inserted at the beginning, npx of new node will always be
    XOR of current head and NULL */
    new->next = start;

    if(start != NULL)
    {
        start->next = XOR(new, start->next);
    }
    start = new;
    return start;
}

// Driver Code 
int main() 
{ 
    // Create following singly linked list 
    // 1->2->3->4 
    struct node* start = newnode(1); 
    
    start->next = newnode(2); 
    start->next->next = newnode(3); 
    start->next->next->next = newnode(4); 
                    
    printf("before conversion :"); 
    print(start); 
                                        
    convert(start);

    printf("after conversion :"); 
    printXOR(start); 

    //other method
    start = insert(start,12);
    start = insert(start,13);
    start = insert(start,14);
    start = insert(start,15);
    printXOR(start); 
                                                
    return 0; 
} 
