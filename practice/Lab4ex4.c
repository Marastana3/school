#include <stdio.h>
#define MAX_ARR_LEN 8

int main(void){
    int arr[MAX_ARR_LEN] = {7, -5, 4, 3, -9, 2, -8};
    int k;
    unsigned count = 0;
    scanf("%d", &k);
    for(int i = 0; i < MAX_ARR_LEN; ++i){
        if(arr[i] > k)
            ++count;
    }
    printf("There are %u elements greater then %d.\n", count, k);
    return 0;
}