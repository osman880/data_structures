#include "stack_array.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Stack_Array
{
	int top;
	int capacity;
	int* array;

}Stack;


Stack* new_stack(int capacity)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack -> capacity = capacity;
	stack -> array = (int*)malloc((stack -> capacity) * sizeof(int));
	stack -> top = -1;

	return stack;
}

int is_empty(Stack* stack)
{
	return stack -> top == -1;
}

int is_full(Stack* stack)
{
	return stack -> top == stack -> capacity - 1;
}


void push(Stack* stack,int data)
{
	if(is_full(stack))
	{
		printf("Stack is full!");
		return;
	}
	else
	{
		stack -> array[++stack -> top] = data;
		printf("%d pushed\n", data);
	}


}

int pop(Stack* stack)
{
	if(is_empty(stack))
	{
		printf("Stack is empty!");
		return 0 ;
	}
	else
	{

		return stack->array[stack->top--];

	}


}

void print_stack_array(Stack* stack)
{
	int i= stack -> top;
	while(i != -1)
	{
		printf("%d ", stack->array[i]);
		i--;
	}

	printf("\n");
}

int peek(Stack* stack)
{
	return stack -> array[stack -> top];
}
