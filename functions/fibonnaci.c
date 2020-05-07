#include <stdio.h>

//prints the fibanocci series till n numbers
void fibonnaciSeries(int n){
	int i, a = 0, b=1,c;
	for(i=0;i<n;i++){
		c = a+b;
		a = b;
		b = c;
		//prints ith fibanoccci number
		printf("%d\n",c);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	//inputting n
	printf("Enter a n\n");
	scanf("%d",&n);
	//calling function to print the first n fibanooci numbers.
	fibonnaciSeries(n);
	return 0;
}