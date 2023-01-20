#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*slinked = single linked list
 *dlinked = doubly linked list
 *clinked = circular linked list */


typedef struct node
{
  int data;
  struct node* next;

}Node;

typedef struct node_d
{
	struct node_d* prev;
	int data;
	struct node_d* next;
}Node_d;



void print_slinked(Node *ptr)
{

  while (NULL != ptr)
  {

    printf("%d ", ptr -> data);
    ptr = ptr->next;

  }


  printf("\n");

}

void print_dlinked(Node_d* head)
{
    struct node_d* temp = head;
    while(NULL != temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void print_clinked(Node* circular_head)
{
    Node* temp = circular_head;

    while (temp->next != circular_head)
    {
		printf("%d ", temp->data);
		temp = temp->next;
        }
    printf("%d\n", temp->data);

}



void data_to_end_slinked(Node **i, int x)
{

    struct node *newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next     = NULL;


    if(NULL == *i)
    {
    	*i = newNode;
    }


    else
    {
    	Node *lastNode = *i;


        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }


        lastNode->next = newNode;
    }

}

void data_to_front_slinked(Node** head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
}

void delete_end_slinked(Node **head)
{

    if (NULL == *head)
    {
        // List empty
        return;
    }

    if (NULL == (*head)->next)
    {
        // one node in the list
        free(*head);
        *head = NULL;
        return;
    }


    struct node *current = *head;

    while (NULL != current->next->next)
    {
        current = current->next;
    }

    // last node delete
    free(current->next);
    current->next = NULL;
}

void delete_front_slinked(Node **head_ref)

{

	if(NULL == *head_ref)
	{
	    printf("Linkeds list is empty");
	    return;
	}
	else
	{
	    Node* temp = *head_ref;
	    *head_ref = temp->next;
	    free(temp);
	}


}

int max_value_slinked(Node *head)
{
	Node* temp = head;

	int max = temp -> data;
	while(NULL != temp)
	{

		if(temp -> data > max)
		{
			max = temp -> data;
		}

		temp = temp->next;
	}

	return max;
}

int min_value_slinked(Node *head)
{
	Node* temp = head;

	int min = temp -> data;
	while(NULL != temp)
	{

		if(temp -> data < min)
		{
			min = temp -> data;
		}

		temp = temp->next;
	}

	return min;
}




void data_to_front_dlinked(Node_d** head, int data)
{

    struct node_d* newNode = malloc(sizeof(struct node_d));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if(NULL != *head ) {
        (*head)->prev = newNode;
    }
    *head = newNode;

}

void data_to_end_dlinked(Node_d **head, int data)
{

    struct node_d *newNode = malloc(sizeof(struct node_d));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;


    if (NULL == *head ) {
        *head = newNode;
        return;
    }


    struct node_d *current = *head;
    while (NULL != current->next) {
        current = current->next;
    }


    current->next = newNode;
    newNode->prev = current;
}

void delete_front_dlinked(Node_d **head)
{

	Node_d* temp = *head;
	*head = temp -> next;
	free(temp);
	(*head) -> prev = NULL;


}

void delete_end_dlinked(Node_d **head)
{
	Node_d* temp = *head;

	while(NULL != temp ->next)
	{
		temp = temp ->next;

	}

	Node_d* temp2 = temp -> prev;
	temp2 -> next = NULL;

	free(temp);


}





void data_to_front_clinked(Node** head, int data)
{

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head;

    if (NULL != *head )
    {
        Node* temp = *head;

        while(temp->next != *head)
        {
        	temp = temp->next;
        }

        temp->next = new_node;

    }

    else
    {

        new_node->next = new_node;

    }

    *head = new_node;
}

void data_to_end_clinked(Node** head, int data){

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    if (NULL == *head )
    {
        new_node->next = new_node;
        *head = new_node;
    }

    else
    {
        Node* temp = *head;
        while(temp->next != *head)
        {
        	temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = *head;
    }
}

void delete_node_clinked(Node** head, int data){

	Node *temp = *head;
	Node *prev;

    if (NULL != temp && temp->data == data)
    {
        prev = temp;
        while (prev->next != *head)
        {
        	prev = prev->next;
        }

        prev->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    while (NULL != temp && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (NULL == temp) //data does not exist
    {
    	return;
    }

    prev->next = temp->next;
    free(temp);
}


