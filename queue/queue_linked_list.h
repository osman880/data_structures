#ifndef QUEUE_H
#define QUEUE_H



typedef struct Queue_Node Queue_Node;
typedef struct Queue Queue;
struct Queue_Node* new_node_queue(int key);
struct Queue* create_queue();
void en_queue(Queue* queue, int key);
void de_queue(struct Queue* queue);
void print_L_queue(Queue* queue);
int if_Lq_empty(Queue* queue);
int peek_L(Queue* queue);
int rear_L(Queue* queue);



#endif
