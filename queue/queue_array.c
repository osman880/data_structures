#include "queue_array.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct Queue_Arr
{
	int front, rear, size;
	int capacity;
	int* array;

}Queue_Arr;


Queue_Arr* create_queue_array(int capacity)
{
	Queue_Arr* queue = (Queue_Arr*)malloc(sizeof(Queue_Arr));

	queue -> capacity = capacity;

	queue -> front = 0;
	queue -> size = 0;

	queue -> rear = capacity - 1;

	queue -> array = (int*)malloc(queue -> capacity * sizeof(int));

	return queue;
}

int is_full_q_array(Queue_Arr* queue)
{
    return (queue -> size == queue -> capacity);
}

int is_empty_q_array(Queue_Arr* queue)
{
    return (queue -> size == 0);
}


void enqueue(Queue_Arr* queue, int data)
{
    if (is_full_q_array(queue))
    {
    	return;
    }



    queue->rear = (queue -> rear + 1) % queue -> capacity;
    queue->array[queue->rear] = data;
    queue->size = queue -> size + 1;

}


int dequeue(Queue_Arr* queue)
{
    if (is_empty_q_array(queue))
    {
    	return 0;
    }

    int data = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue -> capacity;
    queue->size = (queue->size) - 1;
    return data;
}

int peek_q_array(Queue_Arr* queue)
{
    if (is_empty_q_array(queue))
    {
        return 0;

    }

    return queue->array[queue->front];
}


int rear_q_array(Queue_Arr* queue)
{
	if (is_empty_q_array(queue))
	{

	    return 0;

	}

	return queue->array[queue->rear];
}


void print_queue_array(Queue_Arr* queue)
{
	int i;
	for (i = queue->front; i <= queue->rear; i++)
	{
		printf("%d ",queue->array[i]);
	}

	printf("\n");
}





