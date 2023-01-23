typedef struct Stack Stack;
Stack* new_node(int data);
void push(Stack** root, int data);
void pop(Stack** root);
int peek(Stack* root);
void print_stack(Stack *root);
