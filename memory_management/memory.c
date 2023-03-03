
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

int is_empty(Node* root)
{
	return root == NULL;
}

void bellek_al_adresli(Node** root, int start_addr, int size)
{

	Node *current = *root;
	int current_index = 0;
	while (current)
	{

		if (current->bas <= start_addr && current->son >= start_addr + size)
		{
			if (current->bas == start_addr && current->son == start_addr + size)
			{
		    	Node* temporary = *root;
		    	for (int i = 1; i < current_index; i++)
		    	{
		    		temporary = temporary->next;
		    	}

			    printf("1\n");
			    if (current->next != NULL)
			    {

			    	printf("temporary: %d\n", temporary -> bas);
			    	printf("current: %d\n", current -> bas);
			    	printf("current_index: %d\n",current_index);
//			    	Node *temp = current -> next;
//			    	current -> bas = current -> next -> bas;
//			    	current -> son = current -> next -> son;
//			    	current -> next = current -> next -> next;
//			    	free(temp);

			    	if(current_index == 0)
			    	{
			    		// ilk eleman gidiciyse
			    		(*root) = current -> next;
			    	}
			    	else
			    	{
			    		temporary -> next = temporary -> next -> next;
			    		current = current -> next;
			    	}

			    }

			    else
			    {

			    	current = temporary;
			    	temporary -> next = NULL;

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
		current_index += 1;
	}


	printf("bellek_al_adresli(root, %d*kb, %d*kb);\n", start_addr, size);

}


void bellek_al_adressiz(Node** root, int size)
{

    if (is_empty(*root))
    {
    	printf("No node in the list!");
    }


    else if ((*root)->next == NULL)
    {
    	// bir node varsa

        if ((*root)->son - (*root)->bas == size)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->son - (*root)->bas > size)
        {
            (*root)->bas += size; // update start address
        }
    }

    else
    {
    	// birden fazla node varsa
        Node* best_fit_node = NULL;

        int best_fit_node_found = 0;
        int best_fix_index = 0;

        int count_index = 1;
        Node* iter = *root;

        while (iter != NULL)
        {

            if (iter->son - iter->bas >= size)
            {
            	// yeterli memory var mı ?
                if (best_fit_node == NULL || (iter->son - iter->bas) < (best_fit_node->son - best_fit_node->bas))
                {
                    best_fit_node = iter;
                    best_fix_index = count_index;
                }
            }
            iter = iter->next;
            count_index++;
        }

        if (best_fit_node != NULL)
        {
        	// best-fit node found
            if (best_fit_node->son - best_fit_node->bas == size)
            {

                if (best_fit_node == *root)
                {
                    *root = (*root)->next;
                }

                else
                {
                    iter = *root;
                    for (int i = 1; i < best_fix_index - 1; i++)
                    {
                        iter = iter->next;
                    }
                    iter->next = best_fit_node->next;
                }
                free(best_fit_node);
            }

            else
            {
                best_fit_node->bas += size;
            }
        }


    }


    printf("bellek_al_adressiz(&root, %d*kb);\n", size);


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















