#include <stdio.h>
#include "array/array.h"

void arraytest(){


	  int array[5] = {1, 2, 3, 4, 5};
	//  int * array = (int*)malloc(5);
	//  array[0]= 1;
	//  array[1]= 2;
	//  array[2]= 3;
	//  array[3]= 4;
	//  array[4]= 5;

	//  array_size = 5;
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
	//  print_array(array_7, array_size);

	  int* array_8 = modifyArray(array_7,121,"insert", &array_size);
	  print_array(array_8, array_size);

	  int* array_9 = modifyArray(array_8,155,"deneme", &array_size);
	//  print_array(array_9, array_size);
	//





}




int main()
{



arraytest();




	return 0;
}

