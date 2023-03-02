#ifndef MEMORY_H
#define MEMORY_H


typedef struct node
{
  int bas;
  int son;
  struct node* next;

}Node;

void print_linked(Node *ptr);
void bellek_al_adresli(Node** root, int start_addr, int size);
void bellek_iade_et(Node** root, int start_addr, int size);



#endif
