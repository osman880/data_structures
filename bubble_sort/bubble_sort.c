#include "bubble_sort.h"

#include <stdio.h>
#include <stdlib.h>


void bubble_sort(int arr[], int size)
{
	int counter_one, counter_two;

	for(counter_one = 0; counter_one < size-1; counter_one++)
	{
		for(counter_two = 0; counter_two < size - 1 - counter_one; counter_two++)
		{
			if(arr[counter_two] > arr[counter_two + 1])
			{
				swap(&arr[counter_two] ,&arr[counter_two + 1]);
			}
		}
	}

}
