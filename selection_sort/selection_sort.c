#include "selection_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}


void selection_sort(int arr[], int size)
{
	int counter_one, counter_two, min;

	for(counter_one = 0; counter_one < size-1; counter_one++ )
	{

		min = counter_one;
		for(counter_two = counter_one + 1; counter_two < size; counter_two++)
		{
			if(arr[counter_two] < arr[min])
			{
				min = counter_two;
			}

			if(min != counter_one)
			{
				swap(&arr[min],&arr[counter_one]);
			}
		}
	}
}
