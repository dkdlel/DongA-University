#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 100

int main(int argc, char* argv[]){

    int pid, fd[2];
    char path[MAXLINE];

    pipe(fd); // 파이프 생성
    if((pid=fork()) == 0){ // command 1 / 파이프로 입력값을 전송
        strcpy(path,"/usr/bin/");
        close(fd[0]);
        dup2(fd[1],1); // 입출력 재지정
        close(fd[1]);
        strcat(path,argv[1]);
        execl(path,argv[1],NULL);
    }
    else{ // command 2 / 파이프로 부터 입력값을 가져옴
        strcpy(path,"/usr/bin/");
        close(fd[1]);
        dup2(fd[0],0);
        strcat(path,argv[2]);
        execl(path,argv[2],NULL);
    }
    exit(0);
}
