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

//function which creates a list of n nodes
node* createList(){

    int n,data;
    node  *p, *head = NULL;

    printf("\n How many elements to enter?");
    scanf("%d", &n);
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

//return position of the search element
int search(node *head,int search){
	int pos=1;
	while(head != NULL){
		if(head->data == search) return pos;
		head = head->next;
		pos++;
	}
	//not found condition
	return -1;
}

//main
int main(int argc, char const *argv[])
{
	//driver code
	node *head = createList();
	int s;
	printf("element to be searched\n");
	scanf("%d",&s);
	printf("found at %d\n",search(head,s));

	return 0;
}