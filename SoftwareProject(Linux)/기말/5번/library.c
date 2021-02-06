#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include"book.h"

struct book books;
void Scan(char *);
void Print(char *);
void Search(char *);

int main(int argc, char *argv[]){
int type;
printf("원하시는 기능을 고르세요.\n1 : 도서 입력 2 : 도서 리스트 3 : 도서 검색\n");
scanf("%d",&type);
if(type == 1) Scan(argv[1]);
else if(type == 2) Print(argv[1]);
else if(type == 3) Search(argv[1]);
else printf("입력이 잘못되었습니다.\n");
return 0;
}
void Scan(char *argv){
int fd = open(argv,O_WRONLY,0755);
printf("책이름 / 날짜 / 저자 / 가격 / 일련번호\n");
scanf("%s %s %s %d %d",books.name, books.date, books.authors, &books.money, &books.num);
lseek(fd, sizeof(books)*books.num, SEEK_SET);
write(fd, (char*)&books, sizeof(books));
close(fd);
}
void Print(char *argv){
int fd = open(argv,O_RDONLY);
printf("책이름 / 날짜 / 저자 / 가격 / 일련번호\n");
while(read(fd,(char*)&books,sizeof(books)) > 0){
printf("%s %s %s %d %d\n",books.name, books.date, books.authors, books.money, books.num);
}
close(fd);
}
void Search(char *argv){
int fd = open(argv,O_RDONLY);
int idx; // 찾아야할 인덱스
printf("찾으실 일련번호를 입력하세요 : ");
scanf("%d",&idx); printf("\n");
lseek(fd,sizeof(books)*idx, SEEK_SET);
read(fd, (char *)&books, sizeof(books));
printf("책이름 / 날짜 / 저자 / 가격 / 일련번호\n");
printf("%s %s %s %d %d\n",books.name, books.date, books.authors, books.money, books.num);
close(fd);
}
