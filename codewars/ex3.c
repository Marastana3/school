#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

ssize_t find_short (const char *s){
    ssize_t length = strlen(s), index = 0, min = 0, count = 0;
    char aux[MAX_LEN] = ""; 
    strncpy(aux, s, MAX_LEN);

    min = 100;
    for (int i = 0; i < length; ++i){
        if(aux[i] != ' '){
            ++count;
        }
        else{
            if(count < min){
              min = count;
              index = i - min;  
            }
            count = 0;
        }
    }
    return min;
}

int main (void){
    char s[] = "lets talk about C the best language";
    printf("shortest length : %ld\n", find_short(s));
    return 0;
}