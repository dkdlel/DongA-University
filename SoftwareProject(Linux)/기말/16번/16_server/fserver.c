#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
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
    
    int listenfd, connfd, port, clientlen;
    FILE *fp;
    char inmsg[MAXLINE], outmsg[MAXLINE];
    struct sockaddr_in serveraddr, clientaddr;
    struct hostent *hp;
    char *haddrp;
    
    signal(SIGCHLD,SIG_IGN);
    
    if(argc != 2){
        fprintf(stderr, "사용법: %s <port>\n",argv[0]);
        exit(0);
    }
    port = atoi(argv[1]);
    
    if((listenfd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL)) == -1){
        printf("서버 : 소켓을 생성을 실패하였습니다.\n");
        exit(0);
    }
    
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)port);
    if((bind(listenfd, (struct soketaddr *)&serveraddr, sizeof(serveraddr))) == -1){
        printf("서버 : 소켓 바인딩에 실패하였습니다.\n");
        exit(0);
    }
    if((listen(listenfd,5)) == -1){
        printf("서버 : 연결 요청에 실패하였습니다.\n");
        exit(0);
    }
    // 모든 예외가 없는경우
    printf("서버 : 연결 요청을 기다리고 있습니다.\n");
    while(1){
        clientlen = sizeof(clientaddr);
        connfd = accept(listenfd, &clientaddr, &clientlen);
        
        /*클라이언트의 도메인 이름과 IP 주소 결정*/
        hp = gethostbyaddr((char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);
        haddrp = inet_ntoa(clientaddr.sin_addr);
        printf("서버: %s (%s) %d에 연결됨\n",hp->h_name, haddrp, clientaddr.sin_port);
        
        if(fork() == 0){
            printf("한단어만 전송이 가능합니다.\n종료를 원하시면 quit를 입력하세요.\n");
            while(1){
                printf("Server : ");
                fgets(inmsg,MAXLINE,stdin);
                write(connfd, inmsg, strlen(inmsg)+1);
                if(!strcmp(inmsg,"quit\n")) break; // 탈출조건
                
                sleep(3);
                if(readLine(connfd,inmsg))
                printf("Client : %s", inmsg);
                if(!strcmp(inmsg,"quit\n")) break; // 탈출조건
            }
            printf("연결 끝\n");
            close(connfd);
            exit(0);
        }
        else close(connfd);
    }
}
