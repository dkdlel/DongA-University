#include<stdio.h>
int main(int argc, char *argv[]){
char c;
FILE *fp1, *fp2;
if(argc!=3){
fprintf(stderr,"사용법:%s 파일1 파일2\n",argv[0]);
return 1;
}
fp1 = fopen(argv[1],"r");
if(fp1==NULL){
fprintf(stderr,"파일%s열기 오류\n",argv[1]);
return 2;
}
fp2=fopen(argv[2],"a");
while((c=fgetc(fp1))!=EOF){
fputc(c,fp2);
}
fclose(fp1);
fclose(fp2);
return 0;
}

