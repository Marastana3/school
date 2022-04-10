#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

int main(void){
    char buff[MAX_LEN] = "";
    char buff2[MAX_LEN] = "";
    const char sep[] = "1234567890,.?!:;`'\"\\/+=-_~#^&*()[]{}%@ \n\v\t\r";
    
    fgets(buff, MAX_LEN, stdin);
    strncpy(buff2, buff, MAX_LEN);

    char *p = strtok(buff, sep);
    while(p){
        char *aux = strstr(buff2, p);
        *aux = toupper(*aux); 
        p = strtok(NULL, sep);
    }

    printf("%s\n", buff2);

    return 0;
}