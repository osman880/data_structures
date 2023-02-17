
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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
//	Node* prev = NULL;
//	Node* current = (*root);

//	while(NULL != current && current->bas <= start_addr)
//	{
//
//		prev = current;
//		current = current -> next;
//
//
//	}

if(NULL == *root)
{

	*root = malloc(sizeof(Node));
	(*root)->bas = start_addr;
	(*root)->son = start_addr + size;
	(*root)->next = NULL;

}


else
{


	if( (start_addr+size) < (*root) -> bas )
	{
		printf("1\n");
	    Node *new_node = malloc(sizeof(Node));
	    new_node -> bas = start_addr;
	    new_node -> son = start_addr + size;
	    new_node -> next = *root;
	    *root = new_node;

	}

	else if( (start_addr) > (*root) -> son)
	{
		Node *temp = *root;
		printf("2\n");

	    Node *new_node = malloc(sizeof(Node));
	    new_node -> bas = start_addr;
	    new_node -> son = start_addr + size;
	    new_node -> next = NULL;
	    temp -> next = new_node;


	}

	else if( (start_addr + size) == (*root) -> bas )
	{
		printf("3\n");

	    (*root) -> bas = start_addr;


	}

	else if((start_addr) == (*root) -> son)
	{
		printf("4\n");
		(*root) -> son = start_addr + size ;

	}


}



}















