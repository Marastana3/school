#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

int main(void){
    char str[MAX_LEN] = "";
    char aux[MAX_LEN] = "";
    const char sep = "1234567890\n\t\v\r,.;!? ";

    fgets(str, MAX_LEN, stdin);
    strncpy(aux, str, MAX_LEN);

    char *p = NULL;
    p = strtok(str, sep);

    return 0;
}