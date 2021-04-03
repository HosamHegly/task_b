#include <stdio.h>
#include <stdlib.h>



void print (const char * text)
{
   for(int i=0;i<30;i++)
    {
      printf("hello im the %s\n", text);
      usleep(1000000);
    }
}

int main()
{
//creat child
  pid_t id = fork();
  // if child
  if(id==0)
    {
// create grand child
      pid_t id=fork();
      //if grandchild
      if(id==0)
        {
          print("grandson");

        }
        else
          print("son");

    }

  else
    print("father");

 return 0;
}
