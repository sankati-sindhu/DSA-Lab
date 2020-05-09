#include <stdio.h>

//function to add from 1 to n
int sum_natural(int n){
 	int i,sum=0;

 	//loops runs from 1 to n
 	for(i=1;i<=n;i++)
 		sum += i;
 	return sum;
}
int main(int argc, char const *argv[]){
	int n;
	//inputs n
	printf("Enter some n\n");
	scanf("%d",&n);
	//prints sum
	printf("Sum till of %d natural numbers is %d",n,sum_natural(n));
	return 0;
}