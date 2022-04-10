#include <stdio.h>
#include <math.h>

#define MAX_ARR_LEN 16

long double fractional(){

    char c = getchar();
    char arr[MAX_ARR_LEN];
    unsigned i = 0;

    while((c = getchar()) != '\n'){
        arr[i] = c - '0';
        ++i;
    }
    long double x = 0;
    for(int j = 0; j < i; ++j){
        x += arr[j]/(pow(10, j+1));
    }
    return x;
}

int main(void){
    
    printf("%llf", fractional());
    printf("\n");
    printf("%lu", sizeof(long double));

    return 0;
}