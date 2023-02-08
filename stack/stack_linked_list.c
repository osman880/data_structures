#include "stack_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack* next;


}Stack_Linked;


Stack_Linked* new_node(int data)
{
	Stack_Linked* stack_node = (Stack_Linked*)malloc(sizeof(Stack_Linked));
	stack_node -> data = data;
	stack_node -> next = NULL;

	return stack_node;
}


void push_stack_linked(Stack_Linked** root, int data)
{
	Stack_Linked* stack_node = new_node(data);
	stack_node -> next = *root;
	*root = stack_node;
	printf("%d pushed\n", data);

}

int is_empty_linked(Stack_Linked* root)
{
    return !root;
}


void pop_linked(Stack_Linked** root)
{
	if (is_empty_linked(*root))
	{
		printf("Stack is Empty!\n");
		return;
	}
	else
	{
		Stack_Linked* temp = *root;
		*root = (*root) -> next;
		printf("%d popped\n", temp->data );
		free(temp);
	}

}

int peek_linked(Stack_Linked* root)
{
	return root -> data;
}

void print_stack_linked(Stack_Linked *root)
{

  while (NULL != root)
  {

    printf("%d ", root -> data);
    root = root -> next;

  }

  printf("\n");

}
