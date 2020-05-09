#include <stdio.h>
void recRev(char *x, int beg, int end)
{
   char temp;
 
   if (beg >= end)
      return;
 
   temp = *(x+beg);
   *(x+beg) = *(x+end);
   *(x+end)   = temp;
 
   recRev(x, ++beg, --end);
}
int string_ln(char* p){
	int count = 0;
	//runs the loop till the end of the list
	while(*p != '\0'){
		count++;
		p++;
	}
	return count;
}
void rev(char *str)
{
   int len, i;
   char *beg, *end, temp;
 
   len = string_ln(str);
 
   beg = str;
   end = str;
 
   for (i = 0;i < (len - 1 ) ; i++ )
      end++;
   for ( i = 0 ; i < len/2 ; i++ )
   {
      temp = *end;
      *end = *beg;
      *beg = temp;
 
      beg++;
      end--;
   }
}
int main(int argc, char const *argv[])
{
	char str1[30];
	//inputting string
	printf("Enter a string:\n");
	gets(str1);
	printf("reversing string using recursion\n");
	recRev(str1,0,string_ln(str1)-1);
	printf("%s\n",str1);
	printf("Reversing the reversed string using iteration\n");
	rev(str1);
	printf("%s\n",str1);
	return 0;
}