#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

#define STACK_SIZE 10000

char childstack[STACK_SIZE+1];

//functions for each of the clone threads
int run1 (void * params)
{
    char * args[2] = {"./main2_1",NULL};
      execvp(args[0],args);
}
int run2 (void * params)
{
    char * args[2] = {"./main2_2",NULL};
      execvp(args[0],args);
}
int run3 (void * params)
{
    char * args[2] = {"./main2_3",NULL};
      execvp(args[0],args);
}



int main()
{
   //create 2 clone threads on the same level of the main thread
  int cln=clone(run1,childstack+STACK_SIZE,0,0);
  int clnn=clone(run2,childstack+STACK_SIZE,0,0);

  int clnnn=clone(run3,childstack+STACK_SIZE,0,0);

  printf("clone result 1 = %d\n", cln);
    printf("clone result 2 = %d\n", clnn);
    printf("clone result 2 = %d\n", clnnn);
sleep(5);

 return 0;
}
