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

//convert infix two postfix
void in2post(char* exp) { 
	int i, k; 

	stack s; s.top = -1;

	for (i = 0, k = -1; exp[i]; ++i) { 

		//if is a variable
		if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) 
			exp[++k] = exp[i]; 
		
		//if a opening bracket
		else if (exp[i] == '(') 
			push(&s, exp[i]);
		
		//if a closing bracket
		else if (exp[i] == ')'){ 
			//pops all elements form the stack till '('
			while (s.top != -1 && s.arr[s.top] != '(') 
				exp[++k] = pop(&s); 
			//if there is no '('
			if (s.top == -1 && s.arr[s.top] != '(') 
				printf("Invalid expression\n");
			//pops '('			 
			else
				pop(&s); 
		} 
		//if is a operation
		else { 
			//pops till the precendence of stack is greater than current element
			while (s.top != -1 && Prec(exp[i]) <= Prec(s.arr[s.top])) 
				exp[++k] = pop(&s); 
			//pushes the current operation into the stack
			push(&s, exp[i]); 
		} 

	} 
	exp[++k] = pop(&s); 

	exp[++k] = '\0'; 
	printf( "%s", exp ); 
} 

//main
int main() { 
	//driver code
	char exp[] = "a+b*(c^d)+(e-f/g)*c+d"; 
	in2post(exp); 
	return 0; 
} 
