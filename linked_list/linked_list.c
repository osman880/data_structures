#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int data;
  struct node* next;

}node;

struct node_d
{
	struct node_d* prev;
	int data;
	struct node_d* next;
};

void printLinkedlist(struct node *ptr)
{

  while (ptr != NULL)
  {

    printf("%d ", ptr -> data);
    ptr = ptr->next;

  }
  printf("\n");
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

void printdbList(struct node_d* head) {
    struct node_d* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void add_to_front(struct node** head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
}

void deleteLastNode(struct node **head)
{

    if (*head == NULL)
    {
        // List empty
        return;
    }

    if ((*head)->next == NULL)
    {
        // one node in the list
        free(*head);
        *head = NULL;
        return;
    }


    struct node *current = *head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    // last node delete
    free(current->next);
    current->next = NULL;
}

void addToBeginning(struct node_d** head, int data)
{

    struct node_d* newNode = malloc(sizeof(struct node_d));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if(*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;

}

void addToEnd(struct node_d **head, int data)
{

    struct node_d *newNode = malloc(sizeof(struct node_d));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;


    if (*head == NULL) {
        *head = newNode;
        return;
    }


    struct node_d *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }


    current->next = newNode;
    newNode->prev = current;
}
