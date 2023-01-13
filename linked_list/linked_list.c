#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int data;
  struct node* next;

}node;

void printLinkedlist(struct node *ptr)
{

  while (ptr != NULL)
  {

    printf("%d ", ptr -> data);
    ptr = ptr->next;

  }
}

void data_to_linkedlist(struct node **i, int x)
{

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next     = NULL;


    if(*i == NULL)
         *i = newNode;

    else
    {
        struct node *lastNode = *i;


        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }


        lastNode->next = newNode;
    }

}
