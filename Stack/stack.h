#ifndef STACK_H

typedef struct node node;
typedef struct stack stack;

stack* stack_create(void);
void stack_push(stack*, int);
void stack_pop(stack*);
void stack_show(stack*);
void stack_free(stack*);

#endif