#include <stdio.h>
void copystr(char *dest,char *src)
{
    while(*src!='\0')
        *dest++=*src++;
    *dest='\0';
}
int main(int argc, char const *argv[])
{
	char str1[30],str2[30];
	//inputting string
	printf("Enter a string:\n");
	gets(str1);
	copystr(str2,str1);
	printf("String 1:\n");
	printf("%s\n",str1 );
	printf("string 2:\n");
	printf("%s\n",str2 );
	return 0;
}