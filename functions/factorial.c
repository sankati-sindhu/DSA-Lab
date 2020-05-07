#include <stdio.h>

int recurFact(int n){
	//stop condion for recursive stack
	if(n == 0|| n==1)
		return n;
	return n*recurFact(n);
}
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter n\n");
	scanf("%d",&n);
	printf("Factorial of &d is %d\n",n,recurFact(n));
	return 0;
}