#include <stdio.h>

int main (void) {

    unsigned arr[256] = {0};
    int c;

    while((c = fgetc(stdin)) != EOF) {
        ++arr[c];
    }

    for(int i = 0; i < 256; ++i){
        if(arr[i])
            printf("%c - %u times\n", i, arr[i]);
    }

    return 0;
}