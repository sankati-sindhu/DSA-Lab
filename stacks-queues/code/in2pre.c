#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define max 1000

//intializing stack
typedef struct Stack{ 
	int top; 
	char arr[max]; 
}stack; 

//pops a element
char pop(stack *s){ 
	if (s->top != -1) 
		return s->arr[s->top--] ; 
	return '#'; 
} 

//push a element
void push(stack *s, char op){ 
	s->arr[++s->top] = op; 
} 

//preccedence
int Prec(char ch){ 
	switch (ch) { 
	case '+': return 1;
	case '-': return 1; 
	case '*': return 2;
	case '/': return 2; 
	case '^': return 3; 
	} 
	return -1; 
} 
//displays elements from top
void display(stack s){
	int i;
	if(s.top == -1){
		printf("Empty\n");
	}
	for(i =s.top;i>-1;i--){
		printf("%c",s.arr[i]);
	}
	printf("\n");
}
//convert infix two prefix
void in2pre(char* exp) { 
	int i, n; 
	for(n = 0;exp[n];n++);
	stack s; s.top = -1;
	stack pre;pre.top = -1;
	for (i = n-1; i>=0; i--) { 
		//if is a variable
		if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) 
			push(&pre,exp[i]); 
		
		//if a opening bracket(reverse in prefix) therefore '('' = ')'
		else if (exp[i] == ')') 
			push(&s, exp[i]);
		
		//if a closing bracket
		else if (exp[i] == '('){ 
			//pops all elements form the stack till '('
			while (s.top != -1 && s.arr[s.top] != ')') 
				push(&pre,pop(&s)); 
			//if there is no '('
			if (s.top == -1 && s.arr[s.top] != ')') 
				printf("Invalid expression\n");
			//pops '('			 
			else
				pop(&s); 
		} 
		//if is a operation
		else { 
			//pops till the precendence of stack is greater than current element
			while (s.top != -1 && Prec(exp[i]) <= Prec(s.arr[s.top])) 
				push(&pre,pop(&s));  
			//pushes the current operation into the stack
			push(&s, exp[i]); 
		} 
	} 
	push(&pre,pop(&s));
	display(pre); 
	
} 

//main
int main() { 
	//driver code
	char exp[] = "(a-b/c)*(a/k-l)"; 
	printf( "Infix- expression: %s\n", exp ); 
	printf("%s","prefix expression:" );
	in2pre(exp); 
	return 0; 
} 
