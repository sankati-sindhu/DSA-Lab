#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define  max 1000//max elements in stack

//defining stack
typedef struct STACK{
	int ar[max];
	int top;
}stack;

//function to push elements into stack
void push(stack *s, int data){

	//overflow condition
	if(s->top >= max-1){
		printf("overflow\n");
		return;
	}
	s->top++;
	s->ar[s->top] = data;
}

//function to pop elements
int pop(stack *s){

	//underflow condition
	if(s->top < 0) {
		printf("Underflow\n");
		return INT_MIN;
		//raise: if element stored == INT_MIN , the function fails
	}

	int temp = s->ar[s->top];
	s->top--;

	return temp;
}

//return the top elemnt without disturbing the top
int peek(stack s){
	return s.ar[s.top];
}

//displays elements from top
void display(stack s){
	int i;
	if(s.top == -1){
		printf("Empty\n");
	}
	for(i =s.top;i>-1;i--){
		printf("%d\n",s.ar[i]);
	}
	printf("\n");
}

//main
int main(int argc, char const *argv[])
{
	//intialized variables needed
	stack s;
	s.top = -1;
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
				push(&s,data);
				break;
			}
			case 2:{
				data =pop(&s);
				if(data != INT_MIN)
					printf("%d is removed\n",data);
				break;
			}
			case 3:{
				printf("%d is the top\n",peek(s) );
				break;
			}
			case 4:{
				display(s);
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
