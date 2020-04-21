#include <stdio.h>
#define max 1000
//globally initalized stack
char stack[max],top = -1;

//function which return the top element of the global stack
char pop(){

	//underflow condion
	if(top == -1)
		return '0';
	char res = stack[top];
	top--;
	return res;

}

//fuction pushes <char> data into the global stack
void push(char data){
	//overflow condition
	if(top != max-1)
		printf("overflow\n");
	top++;
	stack[top] = data;
}

//main
int main(){
	char string[max];

	//inputting the string
	scanf("%[^\n]%*c",string);
	int i ;

	//pushes all the elements in the string into stack
	for(i = 0;string[i] !='\0';i++){
		push(string[i]);
	}

	//pops all elements from stack a d intializes to string
	for(i=0;i<max;i++){
		int c = pop();
		if(c == '0')
			break;
		string[i] = c;
		
	}

	//prints the string after reversing
	printf("%s",string);
	return 0;
}