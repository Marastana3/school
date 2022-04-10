#include <stdio.h>
#define MAX_ARR_LEN 10

int main(void){
    unsigned n = 0, n_par = 0, n_impar = 0;
    int arr[MAX_ARR_LEN] = {0};
    int arr_par[MAX_ARR_LEN] = {0};
    int arr_impar[MAX_ARR_LEN] = {0};

    printf("n = ");
    scanf("%u", &n);

    for(int i = 0; i < n; ++i){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; ++i){
        if(arr[i] % 2 == 0){
            arr_par[n_par] = arr[i];
            ++n_par;
        }
        else{
            arr_impar[n_impar] = arr[i];
            ++n_impar;
        }
    }
    for(int i = 0; i < n_impar; ++i){
        arr[i] = arr_impar[i];
    }
    for(int i = n_impar, j = 0; i < n && j < n_par; ++i, ++j){
        arr[i] = arr_par[j];
    }

    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}