#include <stdio.h>

int main()
{   char input[100];
    int ch, i;
    FILE* fp;
    fp = fopen("output.txt", "w");
    i = 0;
    while((ch=getchar()) != '\n') input[i++] = ch;
    input[i] = '\0';
    fputs(input, fp);
    
    fclose(fp);
    return 0;
}
