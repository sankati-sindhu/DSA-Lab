#include <stdio.h>
#include <stdlib.h>

//double linked list node
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}node;

node* createNode(int data){
	node *newNode = ((node*)malloc(sizeof(node)));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
//function which creates a double list of 5 nodes
node* createList(){

    int n=5,data;
    node  *p, *head = NULL,*temp;

    //runs loop 5 times
    while(n--){
        printf("Enter a number\n");
        scanf("%d",&data);
        //for the first node
        if(head == NULL){
            //intializing newnode as head
            head = createNode(data);
            p = head;
        }
        //fpr other nodes
        else{
	        temp = createNode(data);
	        p->next = temp;
	        temp->prev = p;
	        p = p->next;
        }
    }
    //return the list of 5nodes
    return head;
    
}

//displays nodes from head to the end
void display(node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

//main
int main(){
	node *head = createList();
	display(head);
	return 0;
}