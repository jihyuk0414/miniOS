#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // fork 함수를 사용하기 위해 필요한 헤더 파일

#define BUFFER_SIZE 25
#define READ_END 0 
#define WRITE_END 1

int ipc(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings\n";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Error occurred");
        return 1; 
    }
    if(pid > 0)
    {
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1); 
    }
    else {
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE); 
        printf("read %s", read_msg); 
        close(fd[READ_END]); 
    }

    return 0;
}
