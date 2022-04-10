#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *disemvowel(const char *str){
    size_t length = strlen(str);
    int i, j;

    char *aux;
    aux = (char*) malloc((length + 1) * sizeof(char));
    if(!aux)
        exit(1);
    strcpy(aux, str);
    
    for(i = 0; i < length; ++i){
        if(aux[i] == 'a' || aux[i] == 'e' || aux[i] == 'i' || aux[i] == 'o' || aux[i] == 'u' ||
           aux[i] == 'A' || aux[i] == 'E' || aux[i] == 'I' || aux[i] == 'O' || aux[i] == 'U'){
               for(j = i; j < length; ++j){
                   aux[j] = aux[j + 1];
               }
               i--;
               length--;
           }
           aux[length + 1] = '\0';
    }
    return aux;
}

int main (void){
    const char str[] = "aaaabbbbuuuuuufffeee";
    printf("%s\n", disemvowel(str));
    return 0;
}