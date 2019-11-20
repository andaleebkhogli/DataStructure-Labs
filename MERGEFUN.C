#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void Merge(int low, int middle, int high);
void MergeSort (int low, int high);



int ar[100]={ 30, 5, 25, 35,20};

int main()
{  int i;
   clrscr();
   printf("\nArray before merge\n");
  for(i=0; i<5; i++)
 {
  printf("\n%d \t" , ar[i]);
 }
   MergeSort( 0, 4);
// int ar[] ={1,2,3};

   printf("\nArray after merge\n");
 for(i=0; i<5; i++)
 {
  printf("\n%d \t" , ar[i]);
 }
 getch();
return 0;
}
void MergeSort (int low, int high)
{ int middle;
  if(low < high)
  {
   middle = (low + high) /2;
   MergeSort(low, middle);
   MergeSort(middle+1,high);
   Merge(low, middle, high);
  }

}

void Merge(int low, int middle, int high)
{
  int temp[100];
  int i;
  int loc = low;
  int list1= low;
  int list2= middle+1;

  while(list1<= middle && list2 <= high)
  {
   if(ar[list1] < ar[list2])
   {
	 temp[loc] = ar[list1];
	 loc++;
	 list1++;

   }
   else
   {
	temp[loc] = ar[list2];
	loc++;
	list2++;
   }

  }
  while(list1 <= middle)
  {
   temp[loc]= ar[list1];
   loc++;
   list1++;

  }
  while (list2 <= high)
  {
   temp[loc] = ar[list2];
   loc++;
   list2++;


  }
  for(i=low; i<=high; i++)
  {
   ar[i] = temp [i];
  }

}