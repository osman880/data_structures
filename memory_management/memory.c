
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void print_linked(Node *ptr)
{
	printf("--------------------------------------------------------------------------------\n");
	while (NULL != ptr)
	{

		printf("%dK-%dK     ", ptr -> bas, ptr -> son);
		ptr = ptr->next;

	}


	printf("\n\n");

}


void bellek_al_adresli(Node** root, int start_addr, int size)
{

	Node *current = *root;
	while (current)
	{
		if (current->bas <= start_addr && current->son >= start_addr + size)
		{
			if (current->bas == start_addr && current->son == start_addr + size)
			{
			    printf("1\n");
			    if (current->next != NULL)
			    {
			    	Node *temp = current -> next;
			    	current -> bas = current -> next -> bas;
			    	current -> son = current -> next -> son;
			    	current -> next = current -> next -> next;
			    	free(temp);

			    }
			    else
			    {
			        *root = NULL;
			    }


			}

			else if(current->bas == start_addr && current->son > start_addr + size)
			{
				printf("2\n");
				current->bas += size;
			}

			else if(current->bas < start_addr && current->son == start_addr + size)
			{
				printf("3\n");
				current->son = start_addr;
			}
			else
			{
				printf("4\n");
				Node* temp = (Node*)malloc(sizeof(Node));
				temp->next = current->next;
				current->next = temp;
				temp->bas = start_addr + size;
				temp->son = current->son;
				current->son = start_addr;
			}
			break;
		}
		current = current->next;
	}


	printf("bellek_al_adresli(root, %d*kb, %d*kb);\n", start_addr, size);

}



void bellek_iade_et(Node** root, int start_addr, int size)
{


	if(NULL == (*root))
	{

		(*root) = (Node*)malloc(sizeof(Node));
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
			new_node -> next = (*root);
			(*root) = new_node;

		}


		else if( (start_addr + size) == (*root) -> bas )
		{
			printf("6\n");
			(*root) -> bas = start_addr;


		}


		else
		{

			Node* iter = (*root);

			while(NULL != iter -> next)
			{
				if(iter->son <= start_addr && iter ->next->bas >= start_addr+size)
				{
					break;
				}

				iter = iter -> next;
			}



			if(start_addr == iter -> son && NULL != iter -> next)
			{


				if( iter -> next -> bas == start_addr + size)
				{
					printf("5\n");
					iter -> son = iter -> next -> son;
					iter -> next = iter -> next -> next;
//					free((iter -> next));   iter -> next'i temp'de tutup temp de tuttuğunu sil

				}

				else if(iter ->next ->bas  >  start_addr + size)
				{
					printf("7\n");
					iter -> son += size;

				}

				else
				{
					printf("--");
				}

			}



			else if (iter -> son < start_addr && NULL != iter -> next)
			{
				if(iter -> next -> bas > start_addr+size)
				{
					printf("2\n");
					Node *new_node = (Node*)malloc(sizeof(Node));
					new_node -> bas = start_addr;
					new_node -> son = start_addr + size;
					new_node -> next = iter -> next;
					iter -> next = new_node;


				}


				else if(iter -> next -> bas == start_addr+size)
				{
					printf("4\n");
					iter -> next -> bas = start_addr;

				}


				else
				{
					printf("--");
				}

			}


			else if(iter -> son == start_addr && NULL == iter ->next)
			{
				printf("8\n");
				iter -> son += size;
			}


			else if(iter -> son < start_addr && NULL == iter ->next)
			{
				printf("9\n");
				Node* new_node = (Node*)malloc(sizeof(Node));
				new_node -> next = NULL;
				iter -> next = new_node;
				new_node -> bas = start_addr;
				new_node -> son = start_addr + size;

			}

			else
			{
				printf("---");
			}

		}

	}

	printf("bellek_iade_et(&pList, %d*kb, %d*kb);\n", start_addr, size);
}















