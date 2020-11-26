/*
 * Author : Nilesh Waghmare <nileshwaghmare3081@gmail.com>
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node{
   uint32_t data;
   struct node *next;
};

struct node *add_at_beg(struct node *last,int num) //this is only for first node
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    
    temp->next = last;
    last = temp;
    last->next = last;
    
    return last;
}

struct node *add_at_end(struct node *last,int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;

    if(last == NULL)
        return add_at_beg(last,num);
    
    temp->next = last->next;
    last->next = temp;

    last=temp;

    return last;
}

struct node *create_ll(struct node *last, int nodes)
{
    int i, num;
    printf("Enter first node to be inserted :");
    scanf("%d",&num);
    
    last=add_at_beg(last,num);

    for(i=2; i<=nodes ;i++)
    {
        last=add_at_end(last,i);
    }
    return last;
}

void print_ll(struct node *last)
{
    struct node *temp = last->next;

    if(last == NULL)
    {   
        printf("empty list\n");
        return;
    }

    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=last->next);

    printf("\n");
}

struct node *add_before_node(struct node *last,int num, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = last->next;

    if(last == NULL)
        return last;

    if(last->data==item)
    {
        last = add_at_beg(last,num);
    }
    
    while(p->next != NULL)
    {
        if(p->next->data==item)
        {
            temp->next = p->next;
            p->next = temp;
            return last;
        }
        p=p->next;
    } 
    return last;
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
            temp->next = p->next;
            p->next = temp;
            return start;
        }
        p=p->next;
    } 
    return start;
}

struct node *add_at_pos(struct node *last, int num, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = last;
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
            temp->next = last;
            last = temp;
        }    
        else
        {
            temp->next = p->next;
            p->next = temp;
        }
    } 
    return last;
}

struct node *delete_node(struct node *last,int num)
{
    struct node *temp, *first = last->next;
    struct node *p = first;

    if(last==NULL)
         return last;
    
    if(first->data==num) //first node
    {
        first = first->next;
        free(p);
        return last;
    }    
    
    while(p->next!=NULL) //delete in between and at the end
    {
        if(p->next->data==num)
        {
            temp=p->next;
            p->next = temp->next;
            free(temp);
            return last;
        }
        p=p->next;
    }
    return last;
}

struct node *reverse(struct node *start)
{
    struct node *ptr = start, *next, *prev = NULL;
    
    while(ptr!=NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        
        prev = ptr;
        ptr = next;
    }    
    start = prev;
    return start;
}

int main()
{
    struct node *last = NULL;
    int nodes;
    printf("Enter number of nodes to be inserted :");
    scanf("%d",&nodes);

    last = create_ll(last, nodes);
    print_ll(last);

    last = add_before_node(last,90,1);
    print_ll(last);
    
    last = add_after_node(last,91,90);
    print_ll(last);
    
    last = add_at_pos(last,92,3);
    print_ll(last);
    
    last = delete_node(last,1);
    print_ll(last);

    //start =reverse(start);
    //print_ll(start);
    
    return 0;
}
