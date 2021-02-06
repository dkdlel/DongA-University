#include<stdio.h>
#include"book.h"
int main(int arg,char *argv[]){
struct book books;
FILE *fp;
if(arg !=2){
fprintf(stderr,"사용법: %s 파일이름\n", argv[0]);
return 1;
}
fp = fopen(argv[1],"wb");
printf("3개의 입력\n");
printf("%5s %5s %5s %5s %5s\n", "책이름","날짜","저자","가격","일련번호");
for(int i = 0 ; i < 3 ; i++){
    scanf("%s %s %s %d %d",books.name, books.date, books.authors, &books.money, &books.num);
    fwrite(&books, sizeof(books), 1, fp);
}
fclose(fp);
return 0;
}
