#include "queue_linked_list.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct Queue_Node
{
	int key;
	struct Queue_Node* next;

}Queue_Node;


typedef struct Queue
{
	Queue_Node *front;
	Queue_Node *rear;

}Queue;


struct Queue_Node* new_node_queue(int key)
{
	Queue_Node* temp = (Queue_Node*)malloc(sizeof(Queue_Node));
	temp->key = key;
	temp->next = NULL;
	return temp;
}


struct Queue* create_queue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue -> front = NULL;
	queue -> rear = NULL;
	return queue;
}


void en_queue(Queue* queue, int key)
{

	Queue_Node* temp = new_node_queue(key);


	if (NULL == queue -> rear)
	{
		queue -> front = temp;
		queue -> rear = temp;
		return;
	}


	queue -> rear -> next = temp;
	queue -> rear = temp;
}


void de_queue(struct Queue* queue)
{

	if (NULL == queue->front)
	{
		return;
	}



	Queue_Node* temp = queue->front;

	queue -> front = queue -> front -> next;


	if (NULL == queue->front )
	{
		queue -> rear = NULL;
	}


	free(temp);
}

void print_L_queue(Queue* queue)
{
    Queue_Node* temp = queue -> front;

    while(temp)
    {
        printf("%d ", temp -> key);
        temp = temp -> next;
    }

    printf("\n");
}

int if_Lq_empty(Queue* queue)
{
	return queue -> front == NULL;
}

int peek_L(Queue* queue)
{
	return queue -> front -> key;
}

int rear_L(Queue* queue)
{
	return queue -> rear -> key;
}
