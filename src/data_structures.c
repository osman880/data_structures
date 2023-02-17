//#include "../array/array.h"
//#include "../array/array.c"

//#include "../linked_list/linked_list.h"
//#include "../linked_list/linked_list.c"

//#include "../stack/stack_linked_list.h"
//#include "../stack/stack_linked_list.c"

//#include "../stack/stack_array.h"
//#include "../stack/stack_array.c"

//#include "../queue/queue_linked_list.h"
//#include "../queue/queue_linked_list.c"

//#include "../queue/queue_array.h"
//#include "../queue/queue_array.c"
//
//#include "../selection_sort/selection_sort.h"
//#include "../selection_sort/selection_sort.c"
//
//#include "../bubble_sort/bubble_sort.h"
//#include "../bubble_sort/bubble_sort.c"

#include "../memory_management/memory.h"
#include "../memory_management/memory.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>





//void arrayget()
//{
//	int array[5] = {1, 2, 3, 4, 5};
//
//	int array_size = sizeof(array)/sizeof(array[0]);
//
//	print_array(array, array_size);
//
//	print_array(reverse_array(array, array_size), array_size);
//
//	int* array_2 = modifyArray(array,15,"insert", &array_size);
//	print_array(array_2, array_size);
//
//	int* array_3 = modifyArray(array_2,25,"insert", &array_size);
//	print_array(array_3, array_size);
//
//
//
//
//	int* array_4 = modifyArray(array_3,3,"delete", &array_size);
//	print_array(array_4, array_size);
//
//	int* array_5 = modifyArray(array_4,4,"delete", &array_size);
//	print_array(array_5, array_size);
//
//	int* array_6 = modifyArray(array_5,5,"delete", &array_size);
//	print_array(array_6, array_size);
//
//	int* array_7 = modifyArray(array_6,55,"delete", &array_size);
//	//print_array(array_7, array_size);
//
//	int* array_8 = modifyArray(array_7,121,"insert", &array_size);
//	print_array(array_8, array_size);
//
//	//int* array_9 = modifyArray(array_8,155,"deneme", &array_size);
//	//print_array(array_9, array_size);
//
//
//	printf("-----------------------------------\n");
//
//	int* newarray1;
//	int new_size = 0;
//
//	insert_data(array_8, 82, &newarray1, array_size, &new_size);
//	print_array(newarray1,new_size);
//
//
//	int* newarray2;
//	insert_data_to_index(newarray1, 32, &newarray2, new_size, 2, &new_size);
//	print_array(newarray2,new_size);
//
//	int* newarray3;
//	delete_data(newarray2, 25, &newarray3, new_size, &new_size);
//
//	print_array(newarray3,new_size);
//
//	int max = find_max(newarray3, new_size);
//	printf("Max is: %d\n", max);
//
//	int min = find_min(array, new_size);
//	printf("Min is: %d\n", min);
//
//}
//
//void linkedlistget()
//{
//	printf("\n---------------------------------------\n\tLinked List\n---------------------------------------\n\n");
//	Node *root = NULL;
//
//	int i =0;
//	for(i=1;i<5;i++)
//	{
//		data_to_end_slinked(&root,i*10);
//	}
//
//	print_slinked(root);
//
//	data_to_front_slinked(&root,5);
//
//	print_slinked(root);
//
//	data_to_front_slinked(&root,12);
//
//	print_slinked(root);
//
//	delete_end_slinked(&root);
//
//	print_slinked(root);
//
//	delete_front_slinked(&root);
//
//	print_slinked(root);
//
//	data_to_front_slinked(&root,50);
//
//	print_slinked(root);
//
//	printf("Max value is: %d", max_value_slinked(root));
//	printf("\nMin value is: %d", min_value_slinked(root));
//
//
//	printf("\n--------------------Doubly Linked List--------------------\n");
//
//	struct node_d* head = NULL;
//
//	data_to_front_dlinked(&head,1);
//	data_to_front_dlinked(&head,2);
//	data_to_front_dlinked(&head,13);
//
//	print_dlinked(head);
//
//	data_to_end_dlinked(&head,65);
//	data_to_end_dlinked(&head,55);
//
//	print_dlinked(head);
//
//	delete_front_dlinked(&head);
//	print_dlinked(head);
//
//	delete_end_dlinked(&head);
//	print_dlinked(head);
//
//
//	printf("\n--------------------Circular Linked List--------------------\n");
//
//	Node* circular_head = NULL;
//
//	data_to_front_clinked(&circular_head,10);
//	data_to_front_clinked(&circular_head,20);
//	print_clinked(circular_head);
//
//	data_to_end_clinked(&circular_head,30);
//	print_clinked(circular_head);
//
//	delete_node_clinked(&circular_head,10);
//	print_clinked(circular_head);
//
//
//
//}
//
//void stack_linked_list_get()
//{
//	printf("\n---------------------------------------\n\tStack\n---------------------------------------\n\n");
//	Stack_Linked* root = NULL;
//	pop_linked(&root);
//	push_stack_linked(&root,10);
//	push_stack_linked(&root,20);
//	push_stack_linked(&root,30);
//	push_stack_linked(&root,40);
//
//	print_stack_linked(root);
//
//	pop_linked(&root);
//	print_stack_linked(root);
//	pop_linked(&root);
//	print_stack_linked(root);
//
//	printf("Top element = %d\n",peek_linked(root));
//}
//
//void stack_array_get()
//{
//	printf("\n---------------------------------------\n\tStack\n---------------------------------------\n\n");
//	Stack* stack = new_stack(10);
//
//	push(stack,10);
//	push(stack,20);
//	push(stack,30);
//	print_stack_array(stack);
//	pop(stack);
//	print_stack_array(stack);
//
//	printf("Top element = %d\n",peek(stack));
//	push(stack,30);
//	print_stack_array(stack);
//	printf("Top element = %d\n",peek(stack));
//	push(stack,40);
//	push(stack,50);
//	push(stack,60);
//	push(stack,70);
//	push(stack,80);
//	push(stack,90);
//	push(stack,100);
//	print_stack_array(stack);
//	push(stack,110);
//
//}
//
//void queue_linked_get()
//{
//	printf("\n---------------------------------------\nQueue\n---------------------------------------\n\n");
//	Queue* q = create_queue();
//	printf("Empty ? : %d\n",if_Lq_empty(q));
//	en_queue(q, 10);
//	en_queue(q, 20);
//	de_queue(q);
//	de_queue(q);
//	en_queue(q, 30);
//	en_queue(q, 40);
//	en_queue(q, 50);
//	print_L_queue(q);
//	printf("Front: %d\n",peek_L(q));
//	printf("Rear: %d\n",rear_L(q));
//	de_queue(q);
//	print_L_queue(q);
//	printf("Empty ? : %d\n",if_Lq_empty(q));
//}
//
//void queue_array_get()
//{
//	Queue_Arr* q = create_queue_array(5);
//	printf("Empty ? : %d\n",is_empty_q_array(q));
//	enqueue(q,10);
//	enqueue(q,20);
//	enqueue(q,30);
//	enqueue(q,40);
//	print_queue_array(q);
//	dequeue(q);
//	print_queue_array(q);
//	printf("\nFront: %d\n",peek_q_array(q));
//	printf("Rear: %d\n",rear_q_array(q));
//	printf("Empty ? : %d\n",is_empty_q_array(q));
//
//}
//
//
//void selection_sort_get()
//{
//
//    int arr[] = {15, 73, 18, 156, 42, 23, 2, 999};
//
//    int size = sizeof(arr)/sizeof(arr[0]);
//
//    print_array(arr, size);
//
//    selection_sort(arr, size);
//
//    printf("Sorted (Selection) array: \n");
//
//    print_array(arr, size);
//
//
//}
//
//
//void bubble_sort_get()
//{
//
//	int arr[] = {15, 73, 18, 156, 42, 23,1, 2, 999};
//
//    int size = sizeof(arr)/sizeof(arr[0]);
//
//    print_array(arr, size);
//
//    bubble_sort(arr, size);
//
//    printf("Sorted (Bubble) array: \n");
//
//    print_array(arr, size);
//
//}

void memory_get()
{
	Node *root = NULL;

	bellek_iade_et(&root,900,5);
	print_linked(root);

//	bellek_iade_et(&root,26,3);
//	print_linked(root);

//	bellek_iade_et(&root,920,10);
//	print_linked(root);

//	bellek_iade_et(&root,899,1);
//	print_linked(root);

	bellek_iade_et(&root,905,5);
	print_linked(root);
}

int main() {

//	arrayget();

//	linkedlistget();

//	stack_linked_list_get();

//	stack_array_get();

//	queue_linked_get();

//	queue_array_get();

//	selection_sort_get();

//	bubble_sort_get();

	memory_get();


  return 0;
}

