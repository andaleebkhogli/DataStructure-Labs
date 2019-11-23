#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<mem.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

struct Node*CreateNode(struct student st);
int AddNode (struct student st);
struct student fillstudent(void);
void PrintStudent(struct student st);
int InsertNode (struct student st,int loc);
int DeleteNode( int loc);
void FreeList (void);
void PrintList (void);
struct student SearchById(int id);
struct student SearchByName(char *n);

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
   struct Node*pNext;


  };

   struct Node*pHead;
   struct Node*pTail;     // both are global 3shan kolo yshofo


int main()
{ int n;
  int loc, num, mssg, mssg2 , mssg3, d;
  char *n1;

  struct student s;
  struct student st;
  clrscr();
  //Menu bt3tna
  printf("1.Add node\n");  //done
  printf("2.Insert node\n"); //done
  printf("3.Search by name\n");
  printf("4.Search by id\n");  //done
  printf("5.Delete node\n"); // done
  printf("6.Free list\n"); // done
  printf("7.Print list\n");//done
  printf("8.Exit\n"); //done


 do
 {

  printf("\nEnter your choice\n");
  scanf("%d",&num);

  switch
  (num)
  {
	case 1:
   s=fillstudent();
   mssg= AddNode(s);
	 if(mssg == 1)
	 {

		printf("Node created successfully\n");
	 }
	else
	 {
		printf("node doesn't created\n");
	}
	break;

	case 2 :
	// int loc ,mssg2 ;
	 printf("Insert your location: \n");
	 scanf("%d" , &loc);
	 mssg2 = InsertNode(s, loc);
	  if(mssg2 == 1)
	  {
	  printf("Your data is inserted\n ");
	  }
	  else
	  {
		printf("Your data is not inserted\n");
	  }
	break;

	case 5 :
	printf("Enter the location you want to delete\n");
	scanf("%d" , &loc);
	mssg3 = DeleteNode (loc);
	if ( mssg3 == 1)
	{
	printf("The node is deleted\n");
	}
	else
	{
	printf ("The node is not deleted\n");
	}
	break;

	case 6 :
	FreeList();
	break;

	 case 7:
	 PrintList();
	 break;

	 case 4:


	 printf ("\nEnter the id you want to search");
	 scanf("%d" ,&d);
	 st = SearchById(d);
	 if (st.id == -1)
	 {
		printf("\nThere's no data found");
	 }
	 else
	 {
	 PrintStudent(st);
	 }
	 break;

	 case 3:
	 printf("\n Enter the name you want to search with\n");
	 scanf("%s", n1);
	 st = SearchByName(n1);
	 if (st.id == -1)
	 {
		printf("\n There's no data found");
	 }
	 else
	 {
	 PrintStudent(st);
	 }

	}
 }  while (num!=8);
 // scanf("%d" , &n);
 // if ( n ==1)
 // {
 //
 //	  printf("Node is added successfully");
 // }
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




   struct Node*CreateNode(struct student st )
   {
		struct Node*ptr;
		ptr=(struct Node*)malloc(sizeof(struct Node));
		if (ptr)
		{
			ptr ->st = st;
			ptr -> pNext = NULL;
			ptr -> pPrev  = NULL;

		}
			return ptr;

   }

	int AddNode (struct student st)
	 {
	  int reval =0;
	  struct Node*ptr;
	  ptr = CreateNode(st);
	  if (ptr)
		{
		  if(!pHead)
		  {
			pHead = pTail = ptr;
		  }
		  else
		  {
			pTail -> pNext = ptr;
			ptr -> pPrev = pTail;
			pTail = ptr;

		  }
		  reval =1;

		}

	  return reval;
	 }

	 int InsertNode(struct student st,int loc)
	 {
	   int retval =0 ,i;
	  struct Node * ptr , *temp;
	  ptr = CreateNode(st);  //create node bt3tna
	  if (ptr)
	  { // law mesh null  w node created
		if (!pHead)     //pHead b null
		 {
		 pHead = pTail = ptr;
		}
		else
		{
		 if (loc == 0)     // there's a list
		 {
			pHead->pPrev = ptr;
			ptr->pNext = pHead;
			pHead = ptr;
		 }
		 else
		 {
		  temp = pHead;
		  for (i=0; i <loc-1 && temp; i++)
		  {
		   temp = temp->pNext;
		  }
		  if (temp == NULL || temp == pTail)
		  {
			pTail->pNext = ptr;
			ptr -> pPrev = pTail;
			pTail = ptr;
		  }
		  else
		  {
			temp->pNext->pPrev = ptr;
			ptr->pNext=temp->pNext;
			ptr ->pPrev = temp;
			temp ->pNext = ptr;
		  }
		 }
		}
		retval =1;
	  }
	  return retval;
	 }



  int DeleteNode(int loc)
  {
   int retval = 0,i;
   struct Node *ptr, *temp;
	if(pHead) //there's a list
	{
	  if (loc == 0) //1st node
	  {
	   ptr = pHead;
	   if (pHead == pTail) //
	   {
			pHead = pTail = NULL;
	   }
	   else
	   {
			pHead = pHead -> pNext;
			pHead ->pPrev = NULL;

	   }
	  free(ptr);
	  retval = 1;
	  }
	 else   // Middle or last
	 {
	   temp = pHead;
	   for (i =0; i <loc && temp; i++)
	   {
		temp = temp ->pNext;     // temp b address mwgoda or NULL msh mwgoda
	   }
	  if (temp)
	  {
	   if ( temp == pTail)
		{
		pTail = pTail ->pPrev;
		pTail ->pNext = NULL;
		}
	   else
	   {
		temp -> pPrev ->pNext = temp ->pNext;
		temp -> pNext -> pPrev = temp ->pPrev;

	   }
	   free(temp);
	  }
	  retval =1;

	 }


	}
	return retval;


  }

  void FreeList (void)     //function bt free el list
  {
   struct Node*temp;
   while (pHead)
   {
	temp =pHead;
	pHead = pHead -> pNext;
	free (temp);

   }
	pTail = NULL; // reached the end of the list
  }


	void PrintList (void)
	{
	 struct Node*ptr;
	 ptr = pHead;
	 printf("the linked data is \n");

	 while (ptr!= NULL)
	 {
	 PrintStudent(ptr -> st);
	 ptr = ptr -> pNext;
	 }
	printf("\n");
	}

	struct student SearchById(int id)
	{
		struct Node*ptr;
		//struct student st;

		ptr = pHead;
		while (ptr && ptr ->st.id !=id )
		{
		 ptr = ptr->pNext;
		}
		 if( !ptr)
		  {
		   ptr->st.id=-1;
		  }

	  return ptr->st;

	}

	struct student SearchByName(char *n1)
	{
	struct Node* ptr;
	ptr =pHead;
	while(ptr && strcmp(ptr->st.name, n1)!=0)
	{
	 ptr = ptr->pNext;
	}
	if (!ptr)
		{
		ptr ->st.id=-1;
		}
	  return ptr -> st;
	}

