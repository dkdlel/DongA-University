#include<stdio.h>
#include<string.h>
#include"book.h"
int main(int argc, char *argv[]){
int type;
struct book books;
FILE *fp;
if(argc != 2){
fprintf(stderr,"사용법:%s 파일이름\n",argv[0]);
return 1;
}
if((fp=fopen(argv[1],"rb"))==NULL){
fprintf(stderr,"파일 열기 오류\n");
return 2;
}
printf("무슨조건으로 검색하시겠습니까?\n0: 도서명 1: 책의 일련번호\n");
scanf("%d",&type);
if(type==0){ //책의 일련번호
char book_name[40];
scanf("%s",book_name);
printf("책이름 / 날짜 / 저자 / 가격 / 일련번호\n");
while(fread(&books,sizeof(books),1,fp) > 0){
if(!strcmp(books.name, book_name)){
printf("%s %s %s %d %d\n",books.name, books.date, books.authors, books.money,books.num);
}
}
}
if(type==1){
int book_num;
scanf("%d",&book_num);
printf("책이름 / 날짜 / 저자 / 가격 / 일련번호\n");
while(fread(&books,sizeof(books),1,fp) > 0){
if(books.num == book_num){
printf("%s %s %s %d %d\n",books.name, books.date, books.authors, books.money, books.num);
}
}
}
fclose(fp);
return 0;
}

