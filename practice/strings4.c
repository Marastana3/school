#include <stdio.h>
#include <string.h>

#define MAX_NAME 10
#define MAX_NAME_LEN 32
#define MAX_LEN 256

int main(void){
    unsigned n;
    printf("n = ");
    scanf("%u", &n);
    char names[MAX_NAME][MAX_NAME_LEN] = {""};
    fgets(names[0], MAX_NAME_LEN, stdin);

    for(int i = 0; i < n; ++i){
        fgets(names[i], MAX_NAME_LEN, stdin);
        names[i][strlen(names[i]) - 1] = '\0';
    }
    char str[MAX_LEN] = "";
    for(int i = 0; i < n-1; ++i){
        strcat(str, names[i]);
        if(i != n-2)
            strcat(str, ", ");
    }
    strcat(str, " si ");
    strcat(str, names[n-1]);
    strcat(str, " invata.");

    printf("%s", str);
    printf("\n");
    return 0;
}