#include <stdio.h>

#define MAX_ARR_LEN 256

double min_from_array(double arr[]){
    double min = arr[1];
    for(int i = 0; i < MAX_ARR_LEN; ++i){
        if(arr[i] < min)
            min = arr[i];
    }
   return min;
}

int main(void){
    double arr[MAX_ARR_LEN] = {7, -5, 4, 3, -9, 2, -8};
    printf("The minimum is: %.0lf\n", min_from_array(arr));
    return 0;
}