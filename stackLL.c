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

//pushes a node into the stack
node* push(node *head,int data){
	node *newNode = createNode(data);
	newNode->next = head;
	return newNode;

}
//pops an element from the stack
node* pop(node *head){
	node *temp = head;
	//node empty thus returns null
	if(head == NULL){
		printf("Empty\n");
		return NULL;
	}
	//deletes the node
	printf("%d deleted\n",temp->data);
	free(temp);
	//returns the stack after popping
	return head->next;
}
//prints the top element
void peek(node *head){
	if(head == NULL) {
		printf("empty\n");
		return;
	}
	printf("%d\n",head->data);
}
//displays the stack from top to the end
void display(node *head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head = head->next;
    }
}
int main(){
	//intialized variables needed
	node *top = NULL;
	int choice,data;

	//runs loop till user chooses exit --> 5
	while(1){
		//menu
		printf("\n1. Push an element on to the STACK.\n"
				"2. Pop and element from the STACK.\n"
				"3. Peek the STACK.\n"
				"4. Display the STACK.\n"
				"5. Exit the program.\n");
		scanf("%d",&choice);
		//performs action according the choice
		switch(choice){
			case 1:{
				printf("\nEnter an element to add\n");
				scanf("%d",&data);
				top = push(top,data);
				break;
			}
			case 2:{
				top = pop(top);
				break;
			}
			case 3:{
				peek(top);
				break;
			}
			case 4:{
				display(top);
				break;
			}
			case 5:{
				exit(0);
				break;
			}
			default: printf("no such option choose again\n");
		}
	}
	return 0;
}