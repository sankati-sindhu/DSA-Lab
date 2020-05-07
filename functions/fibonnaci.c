#include <stdio.h>

void fibonnaciSeries(int n){
	int i, a = 0, b=1,c;
	for(i=0;i<n;i++){
		c = a+b;
		a = b;
		b = c;
		printf("%d\n",c);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter a n\n");
	scanf("%d",&n);
	fibonnaciSeries(n);
	return 0;
}