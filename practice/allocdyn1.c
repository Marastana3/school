#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2){
    char *res = (char*) malloc(strlen(s1) + strlen(s2) + 2);
    if(res == NULL)
        return NULL;
    strcpy(res, s1);
    strcat(res, " ");
    strcat(res, s2);
    return res;
}

int main(void){
    const char *s1 = "Hello,";
    const char *s2 = "World!";
    char *s3 = concat(s1,s2);
    if(s3 != NULL)
        printf("%s", s3);
    free(s3);
    printf("\n");
    return 0;
}