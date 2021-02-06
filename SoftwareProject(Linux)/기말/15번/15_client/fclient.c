#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#define DEFAULT_PROTOCOL 0
#define MAXLINE 100

int readLine(int fd, char *str){
    int n;
    do{
        n = read(fd,str,1);
    }while(n > 0 && *str++ != NULL);
    
    return (n > 0);
}

int main(int argc, char* argv[]){
    
    int clientFd, port, result;
    char *host, inmsg[MAXLINE], outmsg[MAXLINE];
    struct sockaddr_in serverAddr;
    struct hostent *hp;
    
    if(argc != 3){
        fprintf(stderr,"사용법 : %s <host> <port>\n", argv[0]);
        exit(0);
    }
    
    host = argv[1];
    port = atoi(argv[2]);
    clientFd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);
    
    /*서버의 IP주소와 포트 번호를 채운다.*/
    if((hp=gethostbyname(host)) == NULL)
        perror("gethostbyname error\n"); // 호스트 찾기 오류
    bzero((char *)&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)hp->h_addr_list[0], (char *)&serverAddr.sin_addr.s_addr, hp->h_length);
    serverAddr.sin_port = htons(port);
    
    do{ // 연결요청
        result = connect(clientFd, &serverAddr, sizeof(serverAddr));
        if(result == -1) sleep(1);
    }while(result == -1);
    
    while(1){
        printf("변환할 문자열 입력 : ");
        fgets(inmsg, MAXLINE, stdin);
        if(!strcmp(inmsg,"quit\n")) break; // 탈출 조건
        write(clientFd, inmsg, strlen(inmsg)+1); // 변환할 문자열 보내기
        // 소켓으로부터 변환된 문자열을 한 줄 읽어서 프린트
        readLine(clientFd,outmsg);
        printf("--> %s\n",outmsg);
    }
    close(clientFd);
    exit(0);
}
