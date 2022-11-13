#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
   
}
int main(){
   pid_t pid;
   int status;
    
   int i, count, number[25];
   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);
   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
   scanf("%d",&number[i]);

   pid=fork();
   printf("%2d",pid);
   if(pid==-1)
   {
    printf("\nError");
   }
   else if(pid>0)
   { 
    printf("\nparent procss");
    printf("\nchild procss Id: %d parent process Id:%d",getpid(),getppid());
    quicksort(number,0,count-1);
    pid=wait(&status);
   }
   else
   {
    printf("\nchild procss");
    printf("\nchild procss Id: %d parent process Id:%d",getpid(),getppid());
     quicksort(number,0,count-1);
     printf("\nSorted array:");
     for (i=0;i<count;i++)
     {
        printf("%d\t",number[i]);
     }
     return 0;
     
   }
   

}
