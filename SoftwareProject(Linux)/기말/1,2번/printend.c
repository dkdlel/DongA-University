#include<stdio.h>
#include"book.h"
int main(int argc, char *argv[]){
struct book books;
FILE *fp;
if(argc!=2){
fprintf(stderr,"사용법:%s 파일이름\n",argv[0]);
return 1;
}
if((fp=fopen(argv[1],"rb"))==NULL){
fprintf(stderr,"파일 열기 오류\n");
return 2;
}
printf("책이름 / 날짜 / 저자 / 가격 / 일련번호\n");
fseek(fp,0,SEEK_END);
int last_idx = ftell(fp);
int size = last_idx/sizeof(books);
for(int i = 1 ; i <= size ; i++){
fseek(fp,-sizeof(books)*i,SEEK_END); // 이전의 인덱스
fread(&books,sizeof(books),1,fp);
printf("%s %s %s %d %d\n",books.name, books.date, books.authors, books.money, books.num);
}
fclose(fp);
return 0;
}

