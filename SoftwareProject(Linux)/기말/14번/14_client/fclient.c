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
        printf("1 : 업로드  2 : 다운로드  quit : 종료\n");
        scanf("%s",inmsg);
        write(clientFd,inmsg,strlen(inmsg)+1);
        
        if(!strcmp(inmsg,"quit")) break;
        else if(!strcmp(inmsg,"1")){ // 업로드
            printf("파일 이름 입력: ");
            scanf("%s",inmsg);
            write(clientFd,inmsg,strlen(inmsg)+1);
            
            FILE *fp = fopen(inmsg,"r");
            if(fp == NULL){
                write(clientFd, "해당 파일 없음\n", 10);
            }
            else{ // 파일에서 한 줄씩 읽어 소켓을 통해 보낸다
                while(fgets(outmsg, MAXLINE, fp) != NULL){
                    write(clientFd, outmsg, strlen(outmsg)+1);
                }
                fclose(fp);
                printf("업로드 완료\n");
            }
        }
        else if(!strcmp(inmsg,"2")){ // 다운로드
            printf("파일 이름 입력: ");
            scanf("%s",inmsg);
            write(clientFd,inmsg,strlen(inmsg)+1);
            // 파일로 저장
            int fd = open(inmsg, O_CREAT|O_RDWR|O_TRUNC,0755);
            readLine(clientFd,outmsg);
            write(fd,outmsg,strlen(outmsg)+1);
            close(fd);
            printf("다운로드 완료\n");
        }
    }
    close(clientFd);
    exit(0);
}
