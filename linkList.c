#include <stdio.h>
#include <stdlib.h>

//declaration if a node
typedef struct Node{
    int data;
    struct Node *next; 

}node;

//function which creates nodes
node* createNode(int data){
    node *n = ((node*)malloc(sizeof(node)));
    n->data = data;
    n->next = NULL;
    return n;
}

//function which creates a list of 5 nodes
node* createList(){

    int n=5,data;
    node  *p, *head = NULL;

    //runs loop 5 times
    while(n--){
        printf("Enter a number\n");
        scanf("%d",&data);
        if(head == NULL){
            //intializing newnode as head
            head = createNode(data);
            p = head;
        }
        else{
        p->next = createNode(data);
        p = p->next;
        }
    }
    //return the list of 5nodes
    return head;
    
}

//displays elemets in linked list till null
void display(node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//main
int main()
{
    //driver code
    node *head=createList();
    display(head);
    return 0;
}
