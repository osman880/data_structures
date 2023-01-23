#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack* next;


}Stack;


Stack* new_node(int data)
{
	Stack* stack_node = (Stack*)malloc(sizeof(Stack));
	stack_node -> data = data;
	stack_node -> next = NULL;

	return stack_node;
}



void push(Stack** root, int data)
{
	Stack* stack_node = new_node(data);
	stack_node -> next = *root;
	*root = stack_node;
	printf("%d pushed\n", data);

}


void pop(Stack** root)
{
	Stack* temp = *root;
	*root = (*root) -> next;
	printf("%d popped\n", temp->data );
	free(temp);


}

int peek(Stack* root)
{
	return root -> data;
}

void print_stack(Stack *root)
{

  while (NULL != root)
  {

    printf("%d ", root -> data);
    root = root -> next;

  }

  printf("\n");

}
