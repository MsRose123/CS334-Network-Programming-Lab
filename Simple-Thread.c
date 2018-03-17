
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 

void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Hello\n");
    return NULL;
}
  
int main()
{   
    int i;
    pthread_t tid;
    printf("Before Thread\n");
    for(i=0;i<10;i++)
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_join(tid, NULL);
    printf("After Thread\n");
    exit(0);
}
