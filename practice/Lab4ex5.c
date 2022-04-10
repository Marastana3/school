#include <stdio.h>
#define MAX_ARR_LEN 8

int minim(int x, int y, int *arr){
    int min = arr[0];
    for(int i = 1; i < MAX_ARR_LEN; ++i){
        if(arr[i] > x && arr[i] < y){
            if(arr[i] < min )
                min = arr[i];
        }
    }
    return min;
}

int main(void){
    int x, y;
    int arr[MAX_ARR_LEN] = {7, -5, 4, 3, -9, 2, -8};
    scanf("%d %d", &x, &y);
    printf("The minimum is %d.\n", minim(x, y, arr));
    return 0;
}