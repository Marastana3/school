#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat_num(char *s, size_t n, size_t *k){
    size_t digits = 0;
    size_t aux = n;

    while(aux){
        ++digits;
        aux /= 10;
    }

    for(size_t i = *k + digits - 1; i >= *k; --i){
        s[i] = (n % 10) + '0';
        n /= 10;
    }
    *k += digits;
}

char *compress(const char *s){
    size_t len = strlen(s);
    
    char *rez = malloc(len);
    if(!rez)
        exit(EXIT_FAILURE);

    size_t count = 1;
    size_t k = 0;
    int c = s[0];

    for(size_t i = 1; i < len; ++i){
        if(s[i] != c){
            rez[k++] = c;
            if(count > 1)
                concat_num(rez, count, &k);
            count = 1;
            c = s[i];
        }
        else ++count;
    }
    rez[k++] = s[len-1];
    if(count > 1)
        concat_num(rez, count, &k);

    rez[k] = '\0';
    return rez;
}

int main(void){
    char *s = compress("aaaaaaaaaaaabbbbbcddee");
    printf("%s\n", s);
    return 0;
}