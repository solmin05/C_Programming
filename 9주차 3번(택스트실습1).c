#include <stdio.h>
int getLine(char* line){
    int ch;
    int i = 0;
    while((ch = getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
    return i;
}
int main(){
    char input[100];
    FILE* fp;

    // "r"  읽기
    // "w"  쓰기(파일이 존재하면 기존 내용이 사라짐)
    // "a"  확장
    // "r+" 읽기 및 쓰기 (파일이 있어야함)
    // "W+" 읽고 및 쓰기 (없으면 빈파일을 생성)
    // "a+" 읽기 및 확장 (쓰기는 맨 끝으로 이동)
    
    if((fp = fopen("output.txt", "w")) == NULL){
                   //^ 파일 이름   ^파일 열기 모드
        printf("error.....");
        return 0;
    }
    for(int i=0; i<5; i++){
        getLine(input);
        fputs(input, fp);
        fputs("\n", fp);
    
    }
    
    fclose(fp);
    
    return 0;
}
