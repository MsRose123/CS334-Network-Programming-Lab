#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
 
int main()
{
    // We use two pipes
    // First pipe to send input string from parent
    // Second pipe to send concatenated string from child
 
    int fd1[2]; 
    int fd2[2]; 
 
    char fixed_str[] ="Hello World";
    char input_str[100];
    pid_t p;
 
    if (pipe(fd1)==-1)
    {
        printf( "Pipe Failed" );
        exit(0);
    }
    if (pipe(fd2)==-1)
    {
        printf("Pipe Failed" );
        exit(0);
    }
 
    scanf("%s", input_str);
    p = fork();
 
    if (p < 0)
    {
        printf("fork Failed" );
        exit(0);
    }

    else if (p > 0)
    {
        char concat_str[100];
 
        close(fd1[0]);  
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);
 
        wait(NULL);
 
        close(fd2[1]);
        read(fd2[0], concat_str, 100);
        printf("Concatenated string %s\n", concat_str);
        close(fd2[0]);
    }
 
    else
    {
        close(fd1[1]); 
 
        char concat_str[100];
        read(fd1[0], concat_str, 100);
 
        // Concatenate a fixed string with it
        int k = strlen(concat_str);
        int i;
        for (i=0; i<strlen(fixed_str); i++)
            concat_str[k++] = fixed_str[i];
 
        concat_str[k] = '\0';  

        close(fd1[0]);
        close(fd2[0]);
 
        write(fd2[1], concat_str, strlen(concat_str)+1);
        close(fd2[1]);
 
        exit(0);
    }
}
