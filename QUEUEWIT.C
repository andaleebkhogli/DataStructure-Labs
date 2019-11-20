#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct student
  {
	int id;
	char name[20];
	int grades[3];
  };

struct student arr[10];
int tos;

struct student fillstudent(void);
void PrintStudent(struct student st);
struct student DeQueue(void);

int Queue (struct student st) // add
{


  int retval = 0;
  if(tos < 10)
  {
	arr[tos] = st;
	tos++;
	retval =1;

  }
  return retval;


}

struct student DeQueue(void)  //revoke
 {
  struct student st;
  int i;

  if(tos > 0)
   {
	st = arr[0];

	for(i=0; i<tos; i++)
	 {
	  arr[i] = arr[i+1];
	 }
	tos--;
   }
   else
   {
	st.id =-1;
   }
   return st;
 }

 // THIS IS BEGINNING OF MAIN //




struct student fillstudent (void)  //function2   hat5od wala 7aga w tmalh gowa
	{
	struct student s;
	int i;
	printf("Enter student id\n");
	scanf("%d" , &s.id);
	printf("Enter student name\n");
	scanf("%s" , s.name);
	printf("Enter student's grades\n");
	for (i=0; i<3; i ++){
	scanf("%d" , &s.grades[i]);
	}
	return s;

	}


void PrintStudent(struct student s) //function1
	{
	 printf("Id = %d\n" , s.id);
	 printf("Name is %s\n" , s.name);
	 printf("Grades are %d %d %d\n" ,s.grades[0] , s.grades[1] , s.grades[2]);

	}

 int main()
 {
  int n;
  int flag = 1;


  struct student st;

  clrscr();

  printf("1.Queue\n ");
  printf("2.DeQueue\n");
  printf("3.Exit\n");
  printf("Enter your choice");


  do

  {
	scanf("%d" , &n);
  switch (n)
  {
	case 1:
	st = fillstudent();
	Queue(st);
	printf("Queue has worked");
	break;

	case 2:
	st = DeQueue();
	printf("DeQueue has worked");
	break;

	case 3:
	flag =0;

	break;

   }

  }
   while (flag == 1);

  getch();
 return 0;
 }
