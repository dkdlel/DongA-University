#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void alarmHandler(){
    printf("End Signal\n");
    return;
}
int main(int argc, char *argv[]){

    if(argc !=2){
        fprintf(stderr,"사용법: %s 파일이름\n", argv[0]);
        return 1;
    }
    int time = atoi(argv[1]);
    printf("Sleep for %dsecond\n",time);
    signal(SIGALRM,alarmHandler);
    alarm(time);
    pause();
    return 0;
}
