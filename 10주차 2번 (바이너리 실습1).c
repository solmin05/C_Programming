#include <stdio.h>
#define SIZE 100
int main()
{
    char input[SIZE];
    FILE* fp = NULL;
    if((fp = fopen("output.txt", "w")) == NULL){
        printf("error..");
        return 0;
    }
    gets(input);
    //fputs(input, fp); (메모한거 아님)
    fwrite(input,strlen(input), 1,   fp);
    //     ^주소값  ^데이터 크기 ^개수 ^쓸 파일
    fclose(fp);

    return 0;
}
