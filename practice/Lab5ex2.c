#include <stdio.h>
#include <string.h>

#define MAX_LEN 32

int main(void){

    unsigned n = 0;
    printf("n = ");
    scanf("%u", &n);

    char buff[MAX_LEN] = "";
    char name[MAX_LEN] = "";
    fgets(buff, MAX_LEN, stdin);
    for(int i = 0; i < n; ++i){
        fgets(buff, MAX_LEN, stdin);
        buff[strlen(buff)-1] = '\0';
        if(strlen(buff) > strlen(name)){
            strncpy(name, buff, MAX_LEN);
        }
    }
    printf("%s - %lu\n", name, strlen(name));

    printf("\n");
    return 0;
}