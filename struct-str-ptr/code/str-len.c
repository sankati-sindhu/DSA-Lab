#include <stdio.h>

//calculates the length of the string and return the length
int string_ln(char* p){
	int count = 0;
	//runs the loop till the end of the list
	while(*p != '\0'){
		count++;
		p++;
	}
	return count;
}
int main(int argc, char const *argv[])
{
	char str[40];
	//inputting string
	printf("Enter a string:\n");
	gets(str);
	//printing the length
	printf("The length of the entered string is %d\n",string_ln(str));
	return 0;
}