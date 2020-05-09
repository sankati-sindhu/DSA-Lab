#include<stdio.h>
#include <stdlib.h>
//declaration of a node
typedef struct Node{
    int data;
    struct Node *next; 

}node;

struct Queue { 
     node *front, *rear; 
}; 

//function which creates nodes
node* createNode(int data){
    node *n = ((node*)malloc(sizeof(node)));
    n->data = data;
    n->next = NULL;
    return n;
}
void enQueue(struct Queue* q, int data) 
{ 
    // Create a new LL node 
    node* temp = createNode(data); 
  
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    q->rear->next = temp; 
    q->rear = temp; 
} 
void deQueue(struct Queue* q) 
{ 
    if (q->front == NULL) 
        return; 
 
    node* temp = q->front; 
  
    q->front = q->front->next; 
  
    if (q->front == NULL) 
        q->rear = NULL; 
  
    free(temp); 
} 
void display(struct Queue *q){
	node *save = q->front;
	while(q->front != q->rear){
		printf("%d-> ",q->front->data);
		q->front = q->front->next;
	}
	printf("%d\n",q->rear->data );
	q->front = save;
}
int main(int argc, char const *argv[])
{
	//intialized variables needed
    struct Queue *q = ((struct  Queue*)malloc(sizeof(struct Queue)));
	int choice,data;

	//runs loop till user chooses exit --> 5
	while(1){
		//menu
		printf("\n1. EnQueue an element on to the STACK.\n"
				"2. Dequeue and element from the STACK.\n"
				"3. Display the STACK.\n"
				"4. Exit the program.\n");
		scanf("%d",&choice);
		//performs action according the choice
		switch(choice){
			case 1:{
				printf("\nEnter an element to add\n");
				scanf("%d",&data);
				enQueue(q, data); 
				break;
			}
			case 2:{
				deQueue(q); 
				break;
			}
			case 3:{
				display(q);
				break;
			}
			
			case 4:{
				exit(0);
				break;
			}
			default: printf("no such option choose again\n");
		}
	}
	return 0;
}