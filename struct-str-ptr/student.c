#include <stdio.h>

//structure for date
typedef struct Date{
	int month;
	int day;
	int year;

}date;
//structure for student
typedef struct Student{
	char name[30];
	int adminNo;
	date DOB;
	char dept[30];
}student;

int main()
{
	student s[5];
	int i;
	//inputtting the details of 5 students
	printf("Enter details: ");
	for(i=0;i<5;i++){
		printf("Enter\n");
		printf("Name");
		scanf("%[^/n]",&s[i].name);

		printf("Admin No: ");
		scanf("%d",&s[i].adminNo);

		printf("Date of Birth: ");
		scanf("%d%d%d",&s[i].DOB.day,&s[i].DOB.month,&s[i].DOB.year);

		printf("Department: ");
		scanf("%[^/n]",&s.[i].dept);
	}

	//printing details of five students
	printf("\n Details: \n");
	for(i=0;i<5;i++){
		printf("Name: %s\n",s[i].name );
		printf("Admin No: %d\n",s[i].adminNo );
		printf("Date of Birth: %d/%d/%d\n",s[i].DOB.day,s[i].DOB.month,s[i].DOB.year);
		printf("Department: %s\n\n",s[i].dept);
	}
}