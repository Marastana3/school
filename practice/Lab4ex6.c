#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_LEN 6

int main(void){
    unsigned n;
    int arr[MAX_ARR_LEN] = {0};
    scanf("%u", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d ", &arr[i]);
    for(int i = 0; i < n; ++i){
        if(abs(arr[i]) > 10)
            printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}