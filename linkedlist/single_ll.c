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

struct node *add_at_beg(struct node *start,int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = start;
    return temp;
}

struct node *add_at_end(struct node *start,int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = start;

    while(p->next != NULL)
    {
        p=p->next;
    } 
    p->next = temp;
    temp->next = NULL;
    return start;
}

struct node *create_ll(struct node *start, int nodes)
{
    int i, num;
    printf("Eneter first node to be inserted :");
    scanf("%d",&num);
    start=add_at_beg(start,num);

    for(i=2; i<=nodes ;i++)
    {
        start=add_at_end(start,i);
    }
    return start;
}

void print_ll(struct node *start)
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

int getcount(struct node *start)
{
    struct node *temp = start;
    int count=0;
    if(start == NULL)
    {   
        printf("empty list\n");
        return 0;
    }
    
    while(temp != NULL)
    {
        //printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    return count;
}

void print_ll_recursively(struct node *start)
{
    struct node *temp = start;
    if(start == NULL)
    {   
        return;
    }

    print_ll_recursively(temp->next);
    printf("%d ",temp->data);
}

struct node *add_before_node(struct node *start,int num, int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    struct node *p = start;

    if(start == NULL)
        return start;

    if(start->data==item)
    {
        start = add_at_beg(start,num);
    }
    
    while(p->next != NULL)
    {
        if(p->next->data==item)
        {
            temp->next = p->next;
            p->next = temp;
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
            temp->next = p->next;
            p->next = temp;
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
            temp->next = start;
            start = temp;
        }    
        else
        {
            temp->next = p->next;
            p->next = temp;
        }
    } 
    return start;
}

struct node *delete_node(struct node *start,int num)
{
    struct node *temp, *p = start;
    
    if(start==NULL)
         return start;
    
    if(start->data==num) //first node
    {
        start = start->next;
        free(p);
        return start;
    }    
    
    while(p->next!=NULL) //delete in between and at the end
    {
        if(p->next->data==num)
        {
            temp=p->next;
            p->next = temp->next;
            free(temp);
            return start;
        }
        p=p->next;
    }
    return start;
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

struct node *sorted_insert(struct node *start, struct node *new)
{
    if((start==NULL) || (start->data >= new->data))
    {
        new->next = start;
        start = new;
        return start;
    }
    else
    {
        struct node *temp = start;
        while(temp->next!=NULL && (temp->next->data < new->data))
        {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
        return start;
    }
}

struct node *insertion_sort(struct node *start)
{
    struct node *sorted = NULL;
    struct node *temp = start;
    struct node *next;
    
    while(temp != NULL)
    {
        next = temp->next;
        sorted = sorted_insert(sorted, temp);
        temp = next;
    }    
    start = sorted;
}

struct node *middle_as_head(struct node *start)
{
    struct node *temp = start;
    struct node *prev = NULL;
    struct node *middlenode = (struct node *)malloc(sizeof(struct node));;
    int middle;
    
    if(temp!=NULL)
    {
        //find middle
        int count = getcount(temp);
        if(count%2)//odd number
            middle = count/2 + 1;
        else//even
            middle = count/2;
    }
    else 
        return NULL;
    
    while(temp != NULL && (middle-1)!=0)
    {
        prev = temp;
        temp = temp->next;
        middle--;
    }    
    
    middlenode->data = temp->data;

    //printf("middle node data:%d\n",middlenode->data);
    
    prev->next = temp->next;
    free(temp);

    //printf("middle node data:%d\n",middlenode->data);
    middlenode->next = start;
    start = middlenode;
    
    //while(1);
    return start;
}

//Delete Nth node from the end of the given linked list
struct node *delete_nth_from_end(struct node *start,int n)
{
    struct node *temp, *s = start ,*nth = start;
    int i;

    if(start==NULL)
         return start;
    
    for(i=0; nth!=NULL && i<n; i++)
        nth = nth->next;
    
    while(nth->next!=NULL)
    {
        s = s->next;
        nth = nth->next;
    }
    
    //printf("s->data :%d\n",s->data);
    //printf("nth->data :%d\n",nth->data);
    
    free(s->next);
    s->next = s->next->next;

    return start;
}

/* Takes head pointer of the linked list and index 
    as arguments and return data at index*/
int GetNth(struct node *head,int n) 
{ 
    //int count = 1; 
      
    //if count equal too n return node->data 
    if(n==1) 
        return head->data; 
      
    //recursively decrease n and increase  
    // head to next pointer  
    return GetNth(head->next, n-1);  
} 

int main()
{
    struct node *start = NULL;
    int nodes;
    printf("eneter number of nodes to be inserted :");
    scanf("%d",&nodes);

    start = create_ll(start, nodes);
    print_ll(start);

    start = add_before_node(start,90,1);
    print_ll(start);
    
    start = add_after_node(start,91,90);
    print_ll(start);
    
    start = add_at_pos(start,92,3);
    print_ll(start);
    
    start = delete_node(start,1);
    print_ll(start);

    start =reverse(start);
    print_ll(start);

    start = insertion_sort(start);
    print_ll(start);

    printf("print recursively in reverse order\n");
    print_ll_recursively(start);
    printf("\n");

    start = middle_as_head(start);
    print_ll(start);

    printf("delete_nth_from_end nth = 3\n");
    start = delete_nth_from_end(start,3);
    print_ll(start);
	
    printf("retun nth = 3rd element is %d\n",GetNth(start,5));
    print_ll(start);

    return 0;
}
