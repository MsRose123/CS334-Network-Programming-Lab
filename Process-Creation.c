#include <stdio.h>   /* printf, stderr, fprintf */
#include <sys/types.h> /* pid_t */
#include <unistd.h>  /* _exit, fork */
#include <stdlib.h>  /* exit */

void main()
{
   pid_t  pid;
   pid = fork();

   if (pid == -1)
   {
      printf("can't fork, error\n");
      exit(0);
   }
   else if (pid == 0)
   {  
         printf("Child Process\n");
          printf("get.pid :%d\n",getpid());
         exit(0);
   }
   else
   {
     
         printf("Parent Process\n");
         printf("get.pid :%d\n",getpid());
         exit(0);
    }
}
