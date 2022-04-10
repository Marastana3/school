#include <stdio.h>
#define MAX_ARR_LEN 256

unsigned check_and_count(unsigned *arr, unsigned k){
    unsigned count = 0;
    for(int i = 1; i < k; ++i){
        if(arr[i] <= arr[0]){
            arr[i] = 0;
            ++count;
        }
    }
    return count;
}

int main(void){
    unsigned arr[MAX_ARR_LEN] = {0};
    unsigned k = 0;
    while(scanf("%u", &arr[k]) != EOF){
        ++k;
    }
    if(k >= MAX_ARR_LEN){
         printf("Too many elements!\n");
    }
    else{
        for(int i = 0; i < k; ++i)
        printf("%u, ", arr[i]);
     printf("\n");

     unsigned check = check_and_count(arr, k);
     for(int i = 0; i < k; ++i)
        printf("%u, ", arr[i]);
     printf("\n");

     printf("There are %u elemets lesser or equal to %u\n", check, *arr);
    }
    return 0;
}