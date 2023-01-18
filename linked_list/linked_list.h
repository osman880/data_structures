#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node;
struct node_d;
void data_to_linkedlist(struct node **i, int x);
void printLinkedlist(struct node *ptr);

void printdbList(struct node_d* head);
void add_to_front(struct node** head, int data);
void deleteLastNode(struct node **head);
void addToBeginning(struct node_d** head, int data);
void addToEnd(struct node_d **head, int data);





#endif

