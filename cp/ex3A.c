#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

char* reverse_string(char* s){
    unsigned len = strlen(s);
    for(int i = 0; i <= len/2; ++i){
        char aux = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = aux;
    }
    return s;
}

char* reverse_vowel(const char* str){
    char* aux = malloc(strlen(str)+1);
    printf(" "); // ??? Ce pula mea nu mere fara asta
    if(!aux)
        return NULL;
    char s[MAX_LEN] = "";
    strncpy(s, str, MAX_LEN);
    char aux2[MAX_LEN] = "";
    strncpy(aux, s, MAX_LEN);
    static const char vowels[] = "aeiouAEIOU";
    char* p = strtok(s, " ");
    while(p){
        if(strchr(vowels, p[0])){
            char* q = strstr(aux, p);
            strncpy(aux2, q + strlen(p), MAX_LEN);
            strcpy(q, reverse_string(p));
            strcat(aux, aux2);
        }
        p = strtok(NULL, " ");
    }
    return aux;
}

int main(void){
    char* s = reverse_vowel("Iancule mare  apara doamne");
    printf("%s\n", s);
    free(s);
    return 0;
}