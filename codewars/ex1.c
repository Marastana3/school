#include <stdio.h>

void descendingOrder(unsigned *arr, size_t length){
    unsigned aux = 0;
    for(size_t i = 0; i < length - 1; ++i){
        for(size_t j = i + 1; j < length; ++j){
            if(arr[i] < arr[j]){
                aux =  arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
             }
        }
    }

    printf("The descending order : ");
    for(size_t i = 0; i < length; ++i)
        printf("%u ", arr[i]);
    printf("\n");
}

int main(void){
    unsigned arr[] = {1, 2, 3, 4, 5, 6, 8, 10, 14};
    size_t length = sizeof(arr)/sizeof(arr[0]);
    descendingOrder(arr, length);
    return 0;
}