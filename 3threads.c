/* 
gcc -lpthread -o pthread1 pthread1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *print_message_function( void *ptr );
void *print_message_function2( void *ptr );
main()
{
     pthread_t thread1, thread2, thread3;
     char *message1 = "This is Thread 1";
     char *message2 = "This is Thread 2";
     char *message3 = "This is Thread 3";
     int  iret1, iret2, iret3;
    /* Create independent threads each of which will execute function */
     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
     iret3 = pthread_create( &thread3, NULL, print_message_function2, (void*) message3);
     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);
     pthread_join( thread3, NULL);
     
     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     printf("Thread 3 returns: %d\n",iret3);
     exit(0);
}

void *print_message_function( void *ptr ){
     char *message;

     int tid = pthread_self();

     message = (char *) ptr;
     printf("%s \n", message);
     printf("Thread number TID = %d, Process ID %d \n",tid, getpid());
     sleep(10);
}

void *print_message_function2( void *ptr ){
     char *message;
     int tid = pthread_self();

	  message = (char *) ptr;
	  printf("%s \n", message);
	  printf("Thread number TID = %d, Process ID %d \n",tid, getpid());
     sleep(15);
}


