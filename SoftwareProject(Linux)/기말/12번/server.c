#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100
int readLine(int fd, char *str){
int n;
do{
n = read(fd,str,1);
}while(n > 0 && *str++ != NULL);
return (n > 0);
}

int main( ){
int fd1,fd2,len;
char str[MAXLINE],msg[MAXLINE];

unlink("myPipe");
mkfifo("myPipe", 0660);
fd1 = open("myPipe", O_RDONLY);
fd2 = open("myPipe", O_WRONLY);

printf("한단어만 전송이 가능합니다.\n종료를 원하시면 quit를 입력하세요.\n");
while(1){
printf("Server : ");
scanf("%s",msg);
len = strlen(msg)+1; // 문자열의 길이
write(fd2, msg, len);
if(!strcmp(msg,"quit")) break; // 탈출조건

sleep(3);
if(readLine(fd1,str))
printf("Client : %s \n", str);
if(!strcmp(str,"quit")) break; // 탈출조건
}

close(fd1);
close(fd2);
return 0;
}
