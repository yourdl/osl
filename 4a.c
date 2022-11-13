#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *Consume();
void *Produce();
int wrc,rdc;

pthread_mutex_t mute = PTHREAD_MUTEX_INITIALIZER;

// END OF FUNCTION PROTOTYPING


int main()              // definition of Main function
{
  pthread_t thrd1,thrd2;

  pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

  int ret1,ret2;
  int ch,count;
  char che;

  do
  {

   printf("\n\n -----------------------------Deside Initial Priority ------------------------------------ ");
   printf("\n\n1: CONSUMER ");
   printf("\n\n2: PRODUCER ");
   printf("\n\n3: EXIT ");
   printf("\n\t Enter Ur Choice ");
   scanf("%d",&ch);

   switch(ch)
   {
	case 1:
	   printf("\n\n ENTER COUNT FOR PRODUCER AND CONSUMER...");
	   scanf("%d%d",&wrc,&rdc);
	  if(rdc==1)
	  {

	   ret1=pthread_create(&thrd1,NULL,&Consume,NULL);


	   ret2=pthread_create(&thrd2,NULL,&Produce,NULL);
	   pthread_join(thrd1,NULL);
	   pthread_join(thrd2,NULL);
	   }
	  else
	 {
	  printf("\n\n Only One Consumer Is Allowed .. Try Again");
	 }
		break;

	case 2:
	   printf("\n\n ENTER COUNT FOR PRODUCER AND CONSUMER...");
	   scanf("%d%d",&wrc,&rdc);
		if(rdc == 1 || rdc == 0)
	  {

	   ret1=pthread_create(&thrd1,NULL,&Produce,NULL);


	   ret2=pthread_create(&thrd2,NULL,&Consume,NULL);


	   pthread_join(thrd1,NULL);
	   pthread_join(thrd2,NULL);
	  }
	   else
	   {
		 printf("\n\n Only One Consumer Is Allowed .. Try Again");
	   }
	   break;

	case 3:
	   exit(0);      // Exit from loop
	   break;

	default:
	   printf("\n\n Invalid Choice Selection.. Try Again...... ");
   }
   printf("\n\n Do U Wish To Continue [y/n] ");
   scanf("%s",&che);

  }while(che=='y' || che=='Y'); // loop till user's wish..

  return 0;
}

// END OF MAIN FUNCTION


void *Consume()
{
  FILE *fp;
  char txt;
  char str[15];
  int i;
   if(rdc != 0)
  {
   pthread_mutex_lock(&mute);

   printf("\n\n Give Name Which U Wish To Cosume ");
   scanf("%s",&str);     // reading file name to b read

   fp=fopen(str,"r");     // opening file in read mode

   printf("\n\n Contents Of Requested File Are...\n");

   while(!feof(fp))       // reading file till end of file
   {
	  txt=fgetc(fp);
	  printf("%c",txt);    // printing contents of file
   }

   fclose(fp);            // closing previously opened file
   pthread_mutex_unlock(&mute);
  }
}

// END OF CONSUME FUNCTION

void *Produce()
{
   FILE *fs;            // declaring file pointer
   char str[15];
   char text;
   int i;

   for(i=1;i<=wrc;i++)
   {

	pthread_mutex_lock(&mute);

	printf("\n\n Give %d. File Name In Which U Wish To Produce ..",i);
	scanf("%s",&str);   // reading file name to b written

	fs=fopen(str,"a");  // opening file in append mode in order to write contents in the file


	printf("\n\n Inorder To Stop Writting Press Q "); // press Q to stop writting into the file

	printf("\n\n Enter The Text ");
	do
	{
		scanf("%c",&text);  // reading data from keyboard

		if(text!='Q')
		  fputc(text,fs);   // putting data into the desired file

	 }while(text!='Q');     // end of do-while loop

	 fclose(fs);           // closing previously opened file

	pthread_mutex_unlock(&mute);
   }
}

