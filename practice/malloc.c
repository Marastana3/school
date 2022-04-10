#include <stdio.h>
#include <stdlib.h>


int main() {

    int a = 10;
    
    int *b = (int*) malloc(10 * sizeof(int));
    if (!b)
        return 1;
    b[0] = a;
    b[1] = 12;
    printf("%d\n", b[0]);

    b = (int*) realloc(b, 20 * sizeof(int));

    free(b);
    return 0;
}