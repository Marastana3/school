#include <stdio.h>

void print_numbers(long unsigned n){
    printf("%lu, ", n);
    long unsigned next_number = 0;
    while(n > 10){
        next_number = n - (n/10);
        n = next_number;
        printf("%lu, ", next_number);
    }
    printf("\n");
}

int main(void){
    print_numbers(1234);
    return 0;
}