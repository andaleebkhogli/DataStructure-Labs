#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



  struct Node *tos;

 struct student
  {
	int id;
	char name[20];
	int grades[3];
  };


  struct Node
  {
   struct student st;
   struct Node*pPrev;
  };


struct student fillstudent(void);
void PrintStudent(struct student st);
int push(struct student); // btrg3 eza 3mlt push l student wla la2!
struct student pop(void); // lazm trg3 struct student zy el search


 int push(struct student st)
   {
	int retval=0;
	struct Node*ptr;
	ptr=(struct Node*)malloc(sizeof(struct Node));
		if (ptr)
		{
			ptr ->st = st;
			ptr -> pPrev  = NULL;
			if (tos == NULL) // mfyesh haga yeshawr 3leha
			 {

			  tos =ptr;
			 }
			else         //fi already haga byshawr 3leha
			 {
			  ptr-> pPrev = tos;
			  //ptr -> st= st;
			  tos =ptr;

			 }
			 return retval=1;
		}
		 return retval;

	 }

 struct student pop(void)
 {

	struct Node*ptr;
	struct student s;
	if (tos)
	{

	 ptr =tos;
	 tos = tos ->pPrev;
	 s=ptr->st;
	 free(ptr);
	}
	else
	{
	   s.id=-1;

	}
	return s;
 }


 int main()

 {
   int test;
   struct student st;
   clrscr();

   st = fillstudent();
   test = push(st);
   if (test == 1)
   {
	printf("your push is working");
   }

   st = pop();
   if ( st.id == -1)
   {
	printf("\nThere's no students but your pop is working");
   }



 getch();
 return 0;
 }
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

