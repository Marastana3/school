#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *arr = NULL;
    unsigned n = 0;
    int x = 0;

    while(1){
        printf("arr[%u] = ", n);
        scanf("%d", &x);
        if(x == 0)
            break;
        ++n;
        arr = (int*) realloc(arr, n);
        if(arr == NULL){
            printf("Realloc error.\n");
            exit(EXIT_FAILURE);
        }
        arr[n - 1] = x;
    }

    for(int i = n - 1; i >= 0; --i)
        printf("%d", arr[i]);

    printf("\n");
    return 0;
}