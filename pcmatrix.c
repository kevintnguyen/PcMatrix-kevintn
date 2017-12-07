/*
 *  Matrix Task Processor
 *  Based on Operating Systems: Three Easy Pieces by R. Arpaci-Dusseau and A. Arpaci-Dusseau
 * 
 *  Assignment 3 code
 *  Program operates on tasks submitted to the tasks_input directory
 *  Results are created in the tasks_output directory
 *
 *  A bounded buffer is used to store pending tasks
 *  A producer thread reads tasks from the tasks_input directory 
 *  Consumer threads perform tasks in parallel
 *  Program is designed to run as a daemon (i.e. forever) until receiving a request to exit.
 *
 *  This program mimics the client/server processing model without the use of any networking constructs.
 *
 *  Wes J. Lloyd
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Spring 2017
 *
 *  Kevin Nguyen
 *  Assignment 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "matrix.h"
#include "tasks.h"
#include "pcmatrix.h"

/*
/int main() generates the producer and consumer threads. The producer thread digests the readtasks function while the
consumer thread digests the dotask function. Multiple consumer threads could be ran. The integer argument passed by the user
is also used with the producer's readtask's argument so that it could be used with the sleep function.
*/
int main (int argc, char * argv[])
{
int arg=0;
if(argc==2){
arg =(int) argv[1];
}
pthread_t producer;
pthread_t consumer1;
pthread_t consumer2;
pthread_t consumer3;
pthread_t consumer4;

printf("main: begin \n");

pthread_create(&producer, NULL, readtasks, arg); //arg from the user is passed to the readtasks function.
pthread_create(&consumer1, NULL, dotasks, NULL); //dotasks is used with the consumer thread.
//pthread_create(&consumer2, NULL, dotasks, NULL); //multiple dotasks could be used.
//pthread_create(&consumer3, NULL, dotasks, NULL);
//pthread_create(&consumer4, NULL, dotasks, NULL);

pthread_join(producer,NULL);
pthread_join(consumer1,NULL);	
//pthread_join(consumer2,NULL);
//pthread_join(consumer3,NULL);	
//pthread_join(consumer4,NULL);	
  return 0;
}
