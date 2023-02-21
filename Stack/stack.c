#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct stack{
    struct node* top;
};

struct node{
    struct node* next;
    int info;
};


//This function create the stack. 
stack* stack_create(void){
    stack* new = malloc(sizeof(stack));
    new->top = NULL;
    return new;
}


//This function will create a node, and put it at the top of stack.
void stack_push(stack* stck, int number){
    node* newNode = malloc(sizeof(node));   //Do a request to allocate in memory.
        
        if(newNode){
            
            if(!stck->top){                 //if the stack is empty
                newNode->info = number;     
                newNode->next = NULL;
                
                stck->top = newNode;

            } else {                        //if there is/are data in stack.

                newNode->info = number;
                newNode->next = stck->top;

                stck->top = newNode;
            }
        } else {                            //if happens a error at the allocation.
            printf("\nALLOCATION ERROR.");
        }
}



void stack_pop(stack* stck){
    node* aux;                               //Create a auxiliate.

        if(stck->top){
            aux = stck->top;                
                if(stck->top->next){         //if the stack have more than 1 element.
                    stck->top = stck->top->next;
                    aux->next = NULL;
                    printf("%d ", aux->info);  
                    free(aux);               //deallocate the removed element from memory.               

                } else {                     //if there is only one element in the stack.
                    stck->top = NULL;
                    printf("%d ", aux->info);
                    free(aux);               //deallocate the removed element from memory.
                }
        } else {                             //if the stack is empty
            printf("\nThe stack is already empty. There is nothing to be ");
        }
}


//This function will show to the user the elements in the STACK (be careful, when you show a element in the stack, that element will be removed).
void stack_show(stack* stck){
    printf    ("=-=-=-=-=-= STACK =-=-=-=-=-=\n");
    while(stck->top){
        stack_pop(stck);
        printf("\n");
        
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\nThe stack is empty now.\n");  //showing to the user that the stack is empty in the end of function.
}



//This function will deallocate all of the nodes and the stack.
void stack_free(stack* stck){
    node* aux; 
    while(stck->top){               //deallocate all the nodes
            aux = stck->top;                
            if(stck->top->next){            
                    stck->top = stck->top->next;
                    aux->next = NULL;
                    free(aux);
            } else {
                stck->top = NULL;
                free(aux);
            }
    }

    free(stck);                     //deallocate the stack
}



//Main function.
void main(void){
    stack* stack = stack_create();
    int choice, data;

    //Menu
    do{
        printf("\nChoose:\n");
        printf("1) Put the element \n2) Remove the element \n3) Show the stack \n0) Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:
                    stack_free(stack);
                    printf("Exiting...");
                break;

            case 1:
                    printf("Type the value to insert: ");
                    scanf("%d", &data);
                    stack_push(stack, data);
                break;

            case 2:
                    stack_pop(stack);
                    printf("removed from stack.");
                break;

            case 3:
                    stack_show(stack);
                break;

            default:
                    printf("\nTry again, do a available choice.");
                break;
        }

    }while(choice!=0);

    return;
}