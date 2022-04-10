#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 20

int main(void){
    unsigned n, arr[MAX_LEN] = {0}, k = 0;
    bool found =  false;

    printf("n = ");
    scanf("%u", &n);

    for(int i = 0; i < n; ++i){
        printf("arr[%u] = ", i);
        scanf("%u", &arr[i]);
    }

    do{
        found = false;
        for(int i = k; i < n; ++i){
            if(arr[i] % 2 == 1){
                found = true;
                ++n;
                for(int j = n-1; j > i; --j){
                    arr[j] = arr[j-1];
                }
                arr[i] = 0;
                k = i + 2;
                break;
            }
        }
    }while(found);

    for(int i = 0; i < n; ++i)
        printf("%u", arr[i]);
    printf("\n");
    return 0;
}