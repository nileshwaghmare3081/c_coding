/*
 * Author : Nilesh Waghmare <nileshwaghmare3081@gmail.com>
 * */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node{
   uint32_t data;
   struct node *prev;
   struct node *next;
};

struct node *add_at_beg(struct node *start, int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = start;
    temp->prev = NULL;

    //change prev of start to new node
    if(start!=NULL)
        start->prev = temp;

    //move the head to point to the new node
    start = temp;
    return start;
}

struct node *add_at_end(struct node *start,int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    struct node *p = start; //for traversing

    if(start==NULL) //if list is empty make it as new node
    {
        temp->prev = NULL;
        start = temp;
        return start;
    }

    while(p->next != NULL)
    {
        p=p->next;
    } 

    p->next = temp;
    temp->prev = p;
    
    return start;
}

struct node *create_dll(struct node *start, int nodes)
{
    int i, num;
    printf("Eneter first node to be inserted\n");
    scanf("%d",&num);
    start = add_at_beg(start,num);

    for(i=2; i<=nodes ;i++)
    {
        start = add_at_end(start,i);
    }
    return start;
}

void print_dll(struct node *start)
{
    struct node *temp = start;
    if(start == NULL)
    {   
        printf("empty list\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *add_before_node(struct node *start,int num, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = start;

    if(start->data==item)
    {
        start=add_at_beg(start,num);
    }
    
    while(p->next != NULL)
    {
        if(p->next->data==item)
        {
            temp->next = p->next; //make links of next
            p->next = temp;
        
            p->next->prev = temp; //then make links of prev
            temp->prev = p;
            
            return start;
        }
        p=p->next;
    } 
    return start;
}

struct node *add_after_node(struct node *start,int num, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = start;

    if(start == NULL)
        return start;

    while(p != NULL)
    {
        if(p->data==item)
        {
            temp->next = p->next; //next first
            p->next = temp;

            temp->prev = p;       //prev later
            if(temp->next !=NULL)
                temp->next->prev = temp;
            
            return start;
        }
        p=p->next;
    } 
    return start;
}

struct node *add_at_pos(struct node *start, int num, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = start;
    int i;
    
    for(i=0;i<pos-1&&p!=NULL;i++)
    {
        p=p->next;
    }    
    
    if(p==NULL)
        printf("less elements \n");
    else
    {
        if(pos==1)
        {
            //temp->next = start;
            //start = temp;
            return add_at_beg(start, num);
        }    
        else
        {
            temp->next = p->next; //next first
            p->next = temp;

            temp->prev = p;       //prev later
            if(temp->next !=NULL)
                temp->next->prev = temp;
        }
    } 
    return start;
}

struct node *delete_node(struct node *start,int num)
{
    struct node *temp, *p = start;
    
    if(start == NULL)
         return start;
    
    if(start->data == num) //first node
    {
        start = start->next;
        start->prev=NULL;
        free(p);
        return start;
    }    
    
    while(p->next!=NULL) //delete in between and at the end
    {
        if(p->next->data == num)
        {
            temp = p->next;
            p->next = temp->next;
            
            if(p->next!=NULL)
                p->next->prev = p->prev;

            free(temp);
            return start;
        }
        p=p->next;
    }
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *current = start;
    
    while(current != NULL)
    {
        temp->next = current->next;
        temp->prev = current->prev;
        
        current->prev = temp->next;
        current->next = temp->prev;

        current = temp->next;
            
        if(current != NULL)
            start = current;
    }    
    return start;
}

int main()
{
    struct node *start = NULL;
    int nodes;
    printf("eneter number of nodes to be inserted\n");
    scanf("%d",&nodes);

    start = create_dll(start, nodes);
    print_dll(start);

    start = add_before_node(start,90,2);
    print_dll(start);
    
    start = add_after_node(start,91,90);
    print_dll(start);
    
    start = add_at_pos(start,92,3);
    print_dll(start);
    
    start = add_at_pos(start,93,1);
    print_dll(start);
    
    start = delete_node(start,3);
    print_dll(start);

    start =reverse(start);
    print_dll(start);
    
    return 0;
}
