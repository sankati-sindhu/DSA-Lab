#include <stdio.h>
#include <stdlib.h>

//declaration of a node
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

//function which creates a circualar list of 5 nodes
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
    //intializes the last eleemt next to head
    p->next = head;
    //return the list of 5nodes
    return head;
    
}

//displays elemets in linked list till reaches the head
void display(node *head){
    node *ptr = head;
    //if list is not empty
    if(head != NULL){
        while(head->next != ptr){
            printf("%d->",head->data);
            head = head->next;
        }
        printf("%d connected to %d",head->data,ptr->data);
    }
    //if list is empty
    else
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
