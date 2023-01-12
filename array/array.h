#ifndef ARRAY_H
#define ARRAY_H



int find_min(int* array, int size);
int find_max(int* array, int array_size);
void delete_data(int* array, int data, int** newarray, int array_size, int* new_size);
void insert_data_to_index(int* array, int data, int** newarray, int array_size, int index, int* new_size);
void insert_data(int* array, int data, int** newarray, int array_size, int* new_size);
void print_array(int* array, int array_size);
int* modifyArray(int* array, int data, char* operation, int* array_size);
int* reverse_array(int* array, int array_size);



#endif
