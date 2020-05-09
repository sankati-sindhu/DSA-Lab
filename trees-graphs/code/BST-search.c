#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#define initmemory() (struct node*)malloc(sizeof(struct node))

typedef struct node {
    
    int data;
    struct node *left;
    struct node *right;
    
}node;

node* insert(node* root, int data) {
        
    if(root == NULL) {
    
        node* node = initmemory();

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
    
    } else {
            
        if(data <= root->data) { 
            root->left = insert(root->left, data);
        } 

        else {
            root->right = insert(root->right, data);;
        }
        return root;
    }
}
int bstSearch(node* root, int search) 
{ 
	if (root == NULL) 
	return 0;
	if(root->data == search)
	return 1; 
	if (root->data < search) 
	return 2*(bstSearch(root->right, search)); 
	return 2*(bstSearch(root->left, search)); 
} 
int main(int argc, char const *argv[])
{ 
    node* root = NULL;
    
    int num,i,search,data,pos;

    printf("enter initial tree size\n");
    scanf("%d", &num);

    printf("Enter the elements in tree\n");
    for(i=0;i<num;i++){
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nEnter search element\n");
    scanf("%d",&search);
    pos = bstSearch(root,search);
    printf("found at depth %f\n",log2(pos));

	
	return 0;
}