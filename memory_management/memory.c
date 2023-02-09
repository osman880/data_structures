#include "linked_list.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
  int bas;
  int son;
  struct node* next;

}Node;


void print_linked(Node *ptr)
{

  while (NULL != ptr)
  {

    printf("%dK-%dK ", ptr -> bas, ptr -> son);
    ptr = ptr->next;

  }


  printf("\n");

}


void bellek_al_adresli(Node** root, int startAddr, int size)
{

}



void bellek_iade_et(Node** root, int start_addr, int size)
{
	Node* prev = NULL;
	Node* current = (*root);

	while(NULL != current && current->bas <= start_addr)
	{

		prev = current;
		current = current -> next;


	}

	if()
	{
		Node* new_node = malloc(sizeof(Node));
		new_node -> bas = start_addr;
		new_node -> son = start_addr + size;
		print_linked(new_node);



	}

//	current -> son == start_addr + size



}

