#include <stdlib.h>
#include <stdio.h>
int main(){
    int pid;
    pid = fork(); // 자식프로세스 생성
    if(pid == 0){ // 자식이 생성되면
        printf("Child ID : %d\n",getpid());
        pid = fork(); // 자식에서 다시 자식프로세스 생성
        if(pid == 0) // 자식이 생성되면
            printf("Child ID : %d\n",getpid());
        else
            printf("Parent ID : %d\n",getpid());
    }
    else // 자식이 생성되지 않았으면
        printf("Parent ID : %d\n",getpid());

    exit(0); // 자식프로세스 종료
}
