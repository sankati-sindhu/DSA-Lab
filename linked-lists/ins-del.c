#include <stdio.h>
#include <stdlib.h>
#define init() ((struct node*)malloc(sizeof(struct node)))

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}node;

//function which creates nodes
node* createNode(int data){
    node *n = ((node*)malloc(sizeof(node)));
    n->data = data;
    n->next = NULL;
    return n;
}

//inserts a node in the begging
node* insertBeg(node *head,int data){
	node *newNode = createNode(data);
	newNode->next = head;
	return newNode;

}

//inserts at middle
//if nodes = even it adds at nodes/2
//if nodes = odd adds at nodes/2 + 1
void insertMiddle(node *head,int data){

	node *ptr = head;
	if(ptr == NULL){
		//if list empty doesnot add eleemet
		printf("empty\n");
		return;
	}
	//runns till the end
	while(head->next != NULL){
		if(head->next->next != NULL){

			head = head->next->next;//runs fast
			ptr = ptr->next;//runs half the iterations
		}
		else{
			break;
		}
	}
	node *temp = ptr->next;
	ptr->next = createNode(data);
	ptr->next->next = temp;

}

//recusive function which insert the node at the end
node* insertEnd(node *head, int data){
	//if empty return a newlist with one element
	if(head == NULL){
		return createNode(data);
	}
	//calls insertend function
	head->next = insertEnd(head->next, data);
	return head;
	
}

//deletes node in the begging
node* deleteBeg(node *head){
	node *temp = head;
	//node empty thus returns null
	if(head == NULL){
		printf("Empty\n");
		return NULL;
	}
	//ideltes the node
	printf("%d deleted\n",temp->data);
	free(temp);
	//returns the  head's next elements
	return head->next;

}

//deletes the last last node(not recursive)
node* deleteEnd(node *head){

	//if empty list return NULL
	if(head == NULL ){
		printf("empty\n");
		return NULL;
	}
	//if a single element returns NULL
	if (head->next == NULL){
		printf("%d deleted\n",head->data );
		free(head);
		return NULL;
	}
	//last node deleted
	head->next = deleteEnd(head->next);
	return head;
}

//displays the list
void display(node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}
//main
int main () {  
	int choice,data;
	node *head ;
	    while(1){  
	    	//menu
	        printf("\n***Main Menu*\n");  
	        printf("\nChoose one option from the following list ...\n");  
	        printf("\n===============================================\n");  
	        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert middle.\n4.Delete num at the begining \n5.Delete num at the end\n6.Display\n7.Exit\n");  
	        printf("\nEnter your choice?\n");  
	        scanf("\n%d",&choice);

	        //performs operation according to the choice  
	        switch(choice){  
	         
	            case 1:{
	            	printf("Enter the data to be inserted\n");
	            	scanf("%d",&data);
	            	head = insertBeg(head, data);
	            	break;
	            }
	            case 2:{
	            	printf("Enter the data to be inserted\n");
	            	scanf("%d",&data);
	            	head = insertEnd(head, data);
	            	break;
	            }
	            case 3:{
	      
	            	printf("Enter the data to be inserted\n");
	            	scanf("%d",&data);
	            	insertMiddle(head, data);
	            	break;
	            }
	         
	            case 4:{
	            	head = deleteBeg(head);
	            	break;
	            }
	            case 5:{
	            	head = deleteEnd(head);
	            	break;
	            } 
	           	case 6:{
	           		printf("The list:\n");
	           		display(head);
	           		break;

	           	}
	            case 7: {exit(0);break;}
	        }  
	    }
	return 0; 
}  









