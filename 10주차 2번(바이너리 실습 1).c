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
    //fputs(input, fp);
    fwrite(input,strlen(input), 1, fp);
    
    fclose(fp);

    return 0;
}
