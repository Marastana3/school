#include <stdio.h>

int main(void) {
    int c;

    while((c = fgetc(stdin)) != EOF){
        if(c == '\n'){
            fputc('\r', stdout);
        }
        fputc(c, stdout);
    }

    return 0;
}