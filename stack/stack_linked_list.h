#ifndef STACK_H
#define STACK_H


typedef struct Stack Stack_Linked ;
Stack_Linked* new_node(int data);
int is_empty_linked(Stack_Linked* root);
void push_stack_linked(Stack_Linked** root, int data);
void pop_linked(Stack_Linked** root);
int peek_linked(Stack_Linked* root);
void print_stack_linked(Stack_Linked *root);


#endif
