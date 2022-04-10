#include <stdio.h>

#define MAX_LEN 64

unsigned descendingOrder(unsigned number){
    unsigned n = 0, x = 0;
    unsigned arr[MAX_LEN] = {0};
    unsigned aux = 0;

    while(number){
        arr[n++] = number % 10;
        number /= 10;
    }

    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[i] < arr[j]){
                aux =  arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        x = x*10 + arr[i];
    }
    return x;
}

int main(void){
    printf("%u\n", descendingOrder(12345));
    return 0;
}