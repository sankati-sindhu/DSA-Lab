#include <stdio.h>
int strcomp(char *str1,char *str2)
{
    while(*str1 == *str2){
    	if ( *str1 == '\0' || *str2 == '\0' )
         break;
      str1++;
      str2++;
    }
    if( *str1 == '\0' && *str2 == '\0' )
      return 1;
    return 0;

}
int main(int argc, char const *argv[])
{
	char str1[30],str2[30];
	//inputting string
	printf("Enter a string:\n");
	gets(str1);
	printf("Enter a string:\n");
	gets(str2);
	if(strcomp(str1,str2) == 1) printf("Stringers are equal\n");
	else printf("strings are not equal\n");
	return 0;
}