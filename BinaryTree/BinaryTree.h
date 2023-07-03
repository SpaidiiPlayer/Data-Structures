#ifndef BINARYTREE_H

typedef struct node node;

node* create_tree(void);
node* inserTree(node*, int);
node* free_tree(node*);
void show_tree(node*);
#endif