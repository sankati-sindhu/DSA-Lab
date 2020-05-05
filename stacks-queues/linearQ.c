#include <stdio.h>
#include <stdlib.h>
# define MAX_SIZE 100

//adding a eleemt into the queue
void enqueue(int *queue, int *rear,int *front){

    //overflow condition
    if(*rear  == MAX_SIZE-1){

        printf("Overflow\n Aborting...");
        return;
    }
    //inserts a element in rear
    int ele;
    printf("Enter the element to insert");
    scanf("%d",&ele);
    if (*rear == -1)
    {
        *front = 0;
    }
    *rear += 1;
    *(queue+*rear) = ele;
    
}

//displays elements from front to back
void display(int *queue, int rear, int front){
    int i;
    printf("now queue (front.....to .....back:)\n");
    for(i=front;i<rear;i++){
        printf("%d ",*(queue+i));
    }
    printf("%d ",*(queue+rear));
}

//deletes a element form front
void dequeue(int *queue, int *front,int *rear){
    //underflow condition
    if((*front)==-1){
        printf("\nunderflow.. aborting");
        return;
    }
   
    int temp = *(queue+(*front));
    if(*front== *rear){*front= -1; *rear= -1;}
    else{*front = *front + 1;}
    printf("\n%d is deleted",temp);

}
int main(){
    int ans, queue[MAX_SIZE], front = -1, rear = -1;
    //menu
    while(1){
        printf("\nMENU\n"
               "\n1.Insert an element "
               "\n2. delete an element "
               "\n3.Display queue"
               "\n4. Exit");
        scanf("%d",&ans);
        //does according to option choosed
        switch(ans){
            case 1: enqueue(queue, &rear, &front);break;
            case 2: dequeue(queue,&front,&rear);break;
            case 3: display(queue, rear, front);break;
            case 4: exit(0);break;

        }

    }
    return 0;
}
