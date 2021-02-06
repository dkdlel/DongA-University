#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<stdio.h>
int isEmpty(char *, char *);
int main(int argc, char *argv[]){
//   if(argc !=2){
//    fprintf(stderr,"사용법: %s 파일이름\n", argv[0]);
//    return 1;
//    }
    
    DIR *dp;
    struct dirent *d;
    struct stat st;
    
    for(int i = 1 ; i <= argc ; i++){
    dp=opendir(argv[i]);
    d=readdir(dp);
    lstat(argv[i],&st); // 파일 상태 정보 가져오기
    if(S_ISDIR(st.st_mode)){ // 디렉토리 파일이면
        if(isEmpty(argv[i], d->d_name)) // 빈 디렉토리인지 확인
            printf("not empty dir\n");
        else {
            printf("%s dir remove\n",argv[i]);
            remove(argv[i]);
        }
    }
    }
    return 0;
}
int isEmpty(char *dir, char *dir_name){
    DIR *dp;
    struct dirent *d;
    dp=opendir(dir);
    while((d=readdir(dp)) != NULL){
        if(d->d_name[0] == '.') continue; // 예외 처리
        return 1; // 빈 디렉토리가 아님
    }
    return 0; // 빈 디렉토리임
}
