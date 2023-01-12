#include "array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find_min(int* array, int size)
{
    int min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

int find_max(int* array, int array_size)
{
	int max = array[0];

	for(int i=0; i< array_size; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}

	}

	return max;


}

void delete_data(int* array, int data, int** newarray, int array_size, int* new_size)
{
	int find = 0;


	*newarray = malloc((array_size - 1) * sizeof(int));


	for (int i = 0, j = 0; i < array_size; i++)
	{
		if (array[i] != data)
		{
//			*newarray[j] = array[i];
			(*newarray)[j] = array[i];
	        j++;
//		        printf("%d",find);

	      }

	    else
	    {
//		    	printf("girdi %d",!find);
	    	find = 1;
	    }

	}


	if (!find)
	{
		printf("Error: element not found in array\n");
		array_size = array_size + 1;
//			return -1;
	}


	*new_size = array_size - 1;

}


void insert_data_to_index(int* array, int data, int** newarray, int array_size, int index, int* new_size)
{
    if(index >= array_size)
    {
        printf("Invalid index, Please enter valid index\n");
        return;
    }

    *new_size = array_size + 1;
    *newarray = (int*) malloc(*new_size * sizeof(int));

    for (int i = 0; i < index; i++)
    {
        (*newarray)[i] = array[i];
    }

    (*newarray)[index] = data;

    for (int i = index+1; i < array_size+1; i++)
    {
        (*newarray)[i] = array[i-1];
    }
}


void insert_data(int* array, int data, int** newarray, int array_size, int* new_size)
{

    *new_size = array_size + 1;

    *newarray = (int*) malloc(*new_size * sizeof(int));

    for (int i = 0; i < array_size; i++)
    {
        (*newarray)[i] = array[i];
    }

    (*newarray)[array_size] = data;
}


int* modifyArray(int* array, int data, char* operation, int* array_size)

{

	if (strcmp(operation, "insert") == 0) {

		int* new_array = malloc((*array_size+1) * sizeof(int));

//		memset(new_array, 0, array_size+1);


		for(int i=0 ; i < *array_size ; i++){

			new_array[i] = array[i];
		}

		new_array[*array_size] = data;

//		array = new_array;
		*array_size = *array_size +1;

		return new_array;

	}


	else if (strcmp(operation, "delete") == 0)
	{


		int find = 0;


		int* new_arr = malloc((*array_size - 1) * sizeof(int));


		for (int i = 0, j = 0; i < *array_size; i++)
		{
			if (array[i] != data)
			{
				new_arr[j] = array[i];
		        j++;
//		        printf("%d",find);

		      }

		    else
		    {
//		    	printf("girdi %d",!find);
		    	find = 1;
		    }

		}


		if (!find)
		{
			printf("Error: element not found in array\n");
			*array_size = *array_size + 1;
//			return -1;
		}


		*array_size = *array_size - 1;

		array = new_arr;
		return new_arr;
	}


	else
	{

	printf("Error: invalid operation\n");
	return 0 ;

	}

}


int* reverse_array(int* array, int array_size)
{
  for (int i = 0; i < array_size / 2; i++) {
    int temp = array[i];
    array[i] = array[array_size - i - 1];
    array[array_size - i - 1] = temp;
  }
  return array;
}


void print_array(int* array, int array_size)
{

	printf("Array: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
