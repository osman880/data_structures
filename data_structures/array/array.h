/*
 * array.h
 *
 *  Created on: 6 Oca 2023
 *      Author: osman.savas
 */

#ifndef ARRAY_ARRAY_H_
#define ARRAY_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int* array, int array_size);

int* reverse_array(int* array, int array_size);

int* modifyArray(int* array, int data, char* operation, int* array_size);

#endif /* ARRAY_ARRAY_H_ */
