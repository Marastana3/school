#include <stdio.h>
#define MAX_ARR_LEN 256

int main(void){
    unsigned n = 0, k = 0;
    int arr[MAX_ARR_LEN] = {0};
    int arr2[MAX_ARR_LEN] = {0};

    printf("n = ");
    scanf("%u", &n);

    for(int i = 0; i < n; ++i){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n-1; ++i){
        if(arr[i] < arr[i+1])
            continue;
        arr2[k++] = arr[i];
    }
    arr2[k++] = arr[n-1];
    for(int i = 0; i < k; ++i)
        printf("%d ", arr2[i]);
    printf("\n");

    return 0;
}