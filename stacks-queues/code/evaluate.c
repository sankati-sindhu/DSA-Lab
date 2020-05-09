#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define max 1000

//intializing stack
typedef struct Stack{ 
	int top; 
	int arr[max]; 
}stack; 

//pops a element
int pop(stack *s){ 
	if (s->top > -1) 
		return s->arr[s->top--] ; 
	return -1; 
} 

//push a element
void push(stack *s, int op){ 
	s->arr[++s->top] = op; 
} 
//displays elements from top
void display(stack s){
	int i;
	if(s.top == -1){
		printf("Empty\n");
	}
	for(i =s.top;i>-1;i--){
		printf("%d\n",s.arr[i]);
	}
	printf("\n");
}

//evaluation of post fix expression where number are having spaces after them
void evaluatePost(char *exp){
	int i, num = 0;
	stack operand; operand.top = -1;
	for(i= 0;exp[i];i ++){
		//if is a number
		if(exp[i]-'0' >= 0 && exp[i]-'0' <=9){
			//updates the number
			if(num == 0) num = exp[i]-'0';
			else num = num*10 + exp[i]-'0';
		}
		//if is a space
		else if(exp[i] == ' '){
			//pushes the element
			push(&operand, num);
			num = 0;
		}
		//if is a operand
		else{
			//pops two number from stack and performs operations
			int op2 = pop(&operand);
			int op1 = pop(&operand);
			if(op2 == -1 || op1 == -1){
				printf("invalid\n");
				return;
			}
			//pushes the result into the stack
			switch(exp[i]){
				
				case '*':{
					push(&operand, (op1*op2));
					break;
				}
				case '/':{
					push(&operand,(op1/op2));
					break;
				}
				case '+':{
					push(&operand,(op1+op2));
					break;
				}
				case '-':{
					push(&operand,(op1-op2));
					break;
				}
			
			}

		}
	}
	//if the stack is not empty then the ex[ression is invalid
	if(operand.top != 0){ printf("invalid\n");
	//return;
	}
	display(operand);
}

//evaluation of pre fix expression where number are having spaces before them
//is same as post fix expect that it evaluate the expression backward
void evaluatePre(char *exp){
	int n;
	for(n=0;exp[n];n++);
	int i, num = 0;
	stack operand; operand.top = -1;
	for(i = n-1;i>-1;i--){

		if(exp[i]-'0' >= 0 && exp[i]-'0' <=9){
			if(num == 0) num = exp[i]-'0';
			else num = num*10 + exp[i]-'0';
		}
		else if(exp[i] == ' '){
			push(&operand, num);
			num = 0;
		}
		else{
			int op2 = pop(&operand);
			int op1 = pop(&operand);
			if(op2 == -1 || op1 == -1){
				printf("invalid\n");
				return;
			}
			switch(exp[i]){
				
				case '*':{
					push(&operand, (op1*op2));
					break;
				}
				case '/':{
					push(&operand,(op1/op2));
					break;
				}
				case '+':{
					push(&operand,(op1+op2));
					break;
				}
				case '-':{
					push(&operand,(op1-op2));
					break;
				}
			
			}

		}
	}
	if(operand.top != 0){ printf("invalid\n");
	return;
	}
	display(operand);
}
int main(){

	//expression for post should have space after every number and no space anywhere else
	//example "34 45 *23 +/" is valid
	//"3 4 5 * 5 / -" is invalid
	char exp[] = "7 8 +3 2 +/";
	printf("expression = %s\n",exp);
	evaluatePost(exp);
	//expression for post should have space before every number and no space anywhere else
	//example " 34 45* 23+/" is valid
	//" 3 4 5 * 5 / - " is invalid
	char exp2[] = "+ 9* 2 6";
	printf("expression = %s\n",exp2);
	evaluatePre(exp2);
	return 0;
}