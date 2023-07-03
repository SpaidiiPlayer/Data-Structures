//BINARY TREE

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"


struct node{
    int data;
    node* left;
    node* right;
};

//create_tree is a function that will return NULL.
node* create_tree(void){
    return NULL;
}


//Free_tree is a function that will remove all the elements of the tree using recursion.
node* free_tree(node* root){
    if(root){
        root->left = free_tree(root->left);
        root->right = free_tree(root->right);
        free(root);
        return NULL;
    } else {
        return NULL;
    }
}


//InsertTree is a function that insert a new node in the tree.
node* inserTree(node* root, int value){
    if(!root){                                          //If doesn't find a root, it will create a node and insert.
        node* newroot = (node*)malloc(sizeof(node));
        if(newroot){
            newroot->data = value;
            newroot->left = NULL;
            newroot->right = NULL;
            return newroot;
        } else {
            printf("ERRO AO ALOCAR\n");
            return NULL;
        }
    } else {                                              //If find a root, it will compare the value to insert with the root data.
        if(value<=root->data){
            root->left = inserTree(root->left, value);    //if the value be less, will insert in the left leaf
        }
        if(value>root->data){
            root->right = inserTree(root->right, value);  //if the value be greater, will insert in the left leaf
        }
    }
    return root;

}


//Show_tree is a fuction that will show all the elements of tree to the user using recursion.
void show_tree(node* root){
    if(root){                          
        show_tree(root->left);
        printf("%d ", root->data);
        show_tree(root->right);
    } else {
        return;
    }
}


int main(){
    int choice, value;
    node* tree = create_tree();

    do{
        printf("\nChoose:\n");
        printf("1) Put the element \n2) Clear the Tree \n3) Show the Tree \n0) Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:
                tree = free_tree(tree);
                break;

            case 1:
                    printf("Type the value to insert: ");
                    scanf("%d", &value);
                    tree = inserTree(tree, value);
                break;

            case 2:
                tree = free_tree(tree);
                break;

            case 3:
                show_tree(tree);
                break;

            default:
                    printf("\nTry again, do a available choice.");
                break;
        }

    }while(choice!=0);

    return 0;
}

