#ifndef STACK_H
#define STACK_H


typedef struct Stack Stack;
Stack* new_stack(int capacity);
int is_empty(Stack* stack);
int is_full(Stack* stack);
void push(Stack* stack,int data);
int pop(Stack* stack);
void print_stack_array(Stack* stack);
int peek(Stack* stack);




#endif
