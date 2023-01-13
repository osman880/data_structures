#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node* next;

};

void printLinkedlist(struct node *ptr)
{

  while (ptr != NULL)
  {

    printf("%d ", ptr -> data);
    ptr = ptr->next;

  }
}

void data_to_linkedlist(struct node *i, int x)
{
	while(i->next != NULL)
	{
		i = i -> next;
	}

	i->next = (struct node*)malloc(sizeof(struct node));
	i->next->data = x;
	i->next->next = NULL;

}
