#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int kerneljihyuk(int argc, char **argv)
{
	int status;
	pid_t pid = fork();

	if (pid == 0) 
    {
        printf("자식 process를 생성합니다.\n");
        exit(3); // 자식 프로세스 종료 상태 반환
    } 
    else if (pid < 0) 
    {
        printf("Error가 발생했습니다.\n");
        exit(5);
    } 
    else 
    {
        wait(&status); 
        if (WIFEXITED(status)) 
        {
            printf("자식 PROCESS의 동작이 완료되었습니다. 부모 프로세스입니다.\n");
        } 
        else 
        {
            printf("자식 PROCESS가 비정상적으로 종료되었습니다.\n");
        }
    }

	return 0;
}
