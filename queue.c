#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct queue
{
    int front, rear, size;
    unsigned capacity;
	int *arr;
};

struct queue *create_queue(unsigned capacity)
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int *)malloc(sizeof(int) * queue->capacity);
    return queue;
}

int is_full(struct queue *queue)
{
    return queue->size == queue->capacity;
}

int is_empty(struct queue *queue)
{
    return queue->size == 0;
}


int front(struct queue *queue)
{
    if(is_empty(queue))
        return INT_MIN;
    else
        return queue->arr[queue->front];
}

int rear(struct queue *queue)
{
    if(is_empty(queue))
        return INT_MIN;
    else
        return queue->arr[queue->rear];
}

int enqueue(struct queue *queue, int item)
{
    if(is_full(queue))
        return INT_MAX;
    
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size  + 1;
    
    printf("Enqueued item is %d\n",queue->arr[queue->rear]);
    return 0;
}

int dequeue(struct queue *queue)
{
    if(is_empty(queue))
        return INT_MIN;
    
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    
    printf("Dequeued item is %d\n", item);
    return item;
}

int main() 
{ 
    struct queue *queue = create_queue(5);
    
    enqueue(queue, 5);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 12);
    enqueue(queue, 23);
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);


    printf("front item is %d\n", front(queue));
    printf("rear item is %d\n", rear(queue));
    
    return 0;
}
