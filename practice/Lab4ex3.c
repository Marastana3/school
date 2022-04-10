#include <stdio.h>
#define MAX_ARR_LEN 256

unsigned check_if_positive(unsigned n, int *arr){
    unsigned count = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] >= 0)
            ++count;
    }
    return count;
}

void check_if_even(unsigned n, int *arr){
    unsigned count1 = check_if_positive(n, arr);
    unsigned count2 = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] > 0){
            if(arr[i] % 2 == 0)
             ++count2;
        }
    }
    if(count1 == count2)
        printf("All the positive elements are even.\n");
    else
         printf("Not all positive elements are even.\n");
}

int main(void){
    unsigned n;
    int arr[MAX_ARR_LEN] = {0};

    printf("n = ");
    scanf("%u", &n);

    for(int i = 0; i < n; ++i){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    check_if_even(n, arr);
    return 0;
}