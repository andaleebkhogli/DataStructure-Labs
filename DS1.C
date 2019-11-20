#include<stdio.h>
#include<conio.h>
#include<mem.h>
#include<ctype.h>
#include<stdlib.h>



 struct student
  {
	int id;
	char name[20];
	int grades[3];
  };


	void printstudent(struct student std);
	struct student fillstudent(void);

int main()
{
	int i, n;
	struct student *stu;
	stu = (struct student *) malloc(sizeof (struct student));



	//	struct student st;

	//	struct student s[5];
	printf("Enter number of students");
	scanf("%d" , &n);

	for (i =0; i<n; i++)     // hatloop 3ala number of i eli a2l mn 3dd
							 // user da5alo
	{
		stu[i] = fillstudent();
		printstudent (stu[i]);


	}
	clrscr();
	//	st=fillstudent();
	//	printstudent(st);


	getch();
  return 0;
}



void printstudent(struct student st) //function1
{
 printf("Id = %d\n" , st.id);
 printf("Name is %s\n" , st.name);
 printf("Grades are %d %d %d\n" ,st.grades[0] , st.grades[1] , st.grades[2]);

}

struct student fillstudent (void)  //function2   hat5od wala 7aga w tmalh gowa
{
	struct student st;
	printf("Enter student id\n");
	scanf("%d" , &st.id);
	printf("Enter student name\n");
	scanf("%s" , st.name);
	printf("Enter student's grades\n");
	scanf("%d %d %d" , &st.grades[0] , &st.grades[1] , &st.grades[2]);

	return st;

}