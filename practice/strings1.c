#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// "Iova latra ham ham ca cainele care face ham"

unsigned delete_str(char *s1, char *s2){
    size_t length1 = strlen(s1);
    size_t length2 = strlen(s2);
    unsigned count = 0;

    char *aux = malloc(length1+1);
    if(!aux)
        return 0;

    char *p = strstr(s1, s2);
    while(p){
        printf("%s\n", p);
        ++count;
        strcpy(aux, "");
        strncat(aux, s1, p - s1);
        strcat(aux, p + length2);
        strcpy(s1, aux);
        p = strstr(s1, s2);
    }
    free(aux);
    return count;
}

int main(void){
    char s1[] = "Iova latra ham ham ca cainele care face ham";
    char s2[] = "ham";
    printf("%u\n", delete_str(s1, s2));
    return 0;
}