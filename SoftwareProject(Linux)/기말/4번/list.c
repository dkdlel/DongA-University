#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
void listDir(char*);
int main(int argc, char** argv) {

	char* dir;
	if (argc == 1) dir = "."; // 현재디렉터리를대상으로
	else dir = argv[1];

	listDir(dir);
	return 0;
}

void listDir(char* dir) {
	struct dirent* d;
	DIR* dp;
	char path[BUFSIZ + 1];
	struct stat st;
	//printf("dir 생성\n");

	dp = opendir(dir);
	printf("%s      \n", dir);
	while ((d = readdir(dp)) != NULL) {
		if (d->d_name[0] == '.') continue; // 예외 처리
		sprintf(path, "%s/%s", dir, d->d_name);
		lstat(path, &st); // 파일 상태 정보 가져오기
		if (S_ISDIR(st.st_mode)) { // 디렉토리 파일이면
			printf("dir : %s\n", path);
			listDir(path);
		}
		printf("%s\n", path);
	}
	closedir(dp);
}
