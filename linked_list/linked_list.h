#ifndef LINKEDLIST_H
#define LINKEDLIST_H


/*slinked = single linked list
 *dlinked = doubly linked list
 *clinked = circular linked list */


typedef struct node Node;
typedef struct node_d Node_d;

void print_slinked(Node *ptr);
void print_dlinked(Node_d* head);
void print_clinked(Node* circular_head);


void data_to_end_slinked(Node **i, int x);
void data_to_front_slinked(Node** head, int data);
void delete_end_slinked(Node **head);
void delete_front_slinked(Node **head_ref);
int max_value_slinked(Node *head);
int min_value_slinked(Node *head);


void data_to_front_dlinked(Node_d** head, int data);
void data_to_end_dlinked(Node_d **head, int data);
void delete_front_dlinked(Node_d **head);
void delete_end_dlinked(Node_d **head);
void data_to_front_clinked(Node** head, int data);
void data_to_end_clinked(Node** head, int data);
void delete_node_clinked(Node** head, int data);




#endif

