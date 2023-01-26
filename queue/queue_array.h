#ifndef QUEUEE_H
#define QUEUEE_H

typedef struct Queue_Arr Queue_Arr;

Queue_Arr* create_queue_array(int capacity);

int is_full_q_array(Queue_Arr* queue);
int is_empty_q_array(Queue_Arr* queue);

void enqueue(Queue_Arr* queue, int data);
int dequeue(Queue_Arr* queue);
int peek_q_array(Queue_Arr* queue);
int rear_q_array(Queue_Arr* queue);


#endif

