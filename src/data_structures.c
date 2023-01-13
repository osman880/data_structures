/*
 ============================================================================
 Name        : data_structures.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "../array/array.h"
#include "../array/array.c"


#include "../linked_list/linked_list.h"
#include "../linked_list/linked_list.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a{
	int i;
	char c;
};

struct b{
	char c;
	int i;
};



int main(void) {

	int array[5] = {1, 2, 3, 4, 5};

	int array_size = sizeof(array)/sizeof(array[0]);

	print_array(array, array_size);

	print_array(reverse_array(array, array_size), array_size);

	int* array_2 = modifyArray(array,15,"insert", &array_size);
	print_array(array_2, array_size);

	int* array_3 = modifyArray(array_2,25,"insert", &array_size);
	print_array(array_3, array_size);




	int* array_4 = modifyArray(array_3,3,"delete", &array_size);
	print_array(array_4, array_size);

	int* array_5 = modifyArray(array_4,4,"delete", &array_size);
	print_array(array_5, array_size);

	int* array_6 = modifyArray(array_5,5,"delete", &array_size);
	print_array(array_6, array_size);

	int* array_7 = modifyArray(array_6,55,"delete", &array_size);
	//print_array(array_7, array_size);

	int* array_8 = modifyArray(array_7,121,"insert", &array_size);
	print_array(array_8, array_size);

	//int* array_9 = modifyArray(array_8,155,"deneme", &array_size);
	//print_array(array_9, array_size);


	printf("-----------------------------------\n");

	int* newarray1;
	int new_size = 0;

	insert_data(array_8, 82, &newarray1, array_size, &new_size);
	print_array(newarray1,new_size);


	int* newarray2;
	insert_data_to_index(newarray1, 32, &newarray2, new_size, 2, &new_size);
	print_array(newarray2,new_size);

	int* newarray3;
	delete_data(newarray2, 25, &newarray3, new_size, &new_size);

	print_array(newarray3,new_size);

	int max = find_max(newarray3, new_size);
	printf("Max is: %d\n", max);

	int min = find_min(array, new_size);
	printf("Min is: %d\n", min);


  printf("---------------------------------------\n---------------------------------------\n\tLinked List\n---------------------------------------\n\n");

	struct node *root;

	root = malloc(sizeof(struct node));
	root -> data = 0;
	root -> next = NULL;


	int i =0;
	for(i=1;i<5;i++)
	{
		data_to_linkedlist(root,i*10);
	}

	printLinkedlist(root);


  return 0;
}

