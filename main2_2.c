#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

#define STACK_SIZE 10000

char childstack[STACK_SIZE+1];


void print (const char * text)
{
   for(int i=0;i<30;i++)
    {
      printf("hello im the %s\n", text);
      usleep(1000000);
    }
}

// the function that the clones will run
int child (void* params)
{
  print("clone thread");
}


int main()
{
   //create 2 clone threads on the same level of the main thread
  int cln=clone(child,childstack+STACK_SIZE,CLONE_PARENT,0);
  int clnn=clone(child,childstack+STACK_SIZE,CLONE_PARENT,0);

  printf("clone result 1 = %d\n", cln);
    printf("clone result 2 = %d\n", clnn);
  print("father thread");
 return 0;
}
