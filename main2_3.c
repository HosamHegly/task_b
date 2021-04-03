#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <syslog.h>

int main()
{
  pid_t id=fork();
  
  if(id==0)
   { 
     //change to root dir
     chdir("/");
     //move to another session
     setsid();

     printf("starting deamon thread\n");
     //close input and output channels
     close(stdin);
     close(stdout);
     close(stderr);

     //open log and write in it
     openlog("myDaemon", LOG_PID, LOG_DAEMON);
     syslog(LOG_NOTICE, "deamon started");
     sleep(1);
     syslog(LOG_NOTICE, "deamon doing work");
     sleep(1);
     syslog(LOG_NOTICE, "deamon ending");
   }
  else
{
   sleep(5);
    printf("deamon pid is%d\n",id);
}
return 0;
}
