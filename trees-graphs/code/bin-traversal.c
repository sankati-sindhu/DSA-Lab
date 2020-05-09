#include <stdio.h>
#include <stdlib.h>
#define initmemory() (struct node*)malloc(sizeof(struct node))

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert(){
    struct node *newnode;
    int x;
    printf("Enter data:");
    scanf("%d",&x);

    if(x==-1)
        return NULL;

    newnode = initmemory();
    newnode->data = x;
    printf("left child of %d:\n",x);
    newnode->left = insert();
    printf("right child of %d:\n",x);
    newnode->right = insert();
    return newnode;

}

void postOrder(struct node *root) {
    if (root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

void inOrder(struct node *root) {
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder( struct node *root) {
    if(root == NULL)return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
  
    struct node* root = insert();
    
    int num,i;
    int data;

    printf("\nPost Order:\n");
    postOrder(root);

    printf("\nPre Order\n");
    preOrder(root);

    printf("\nIn Order\n");
    inOrder(root);
    return 0;
}

