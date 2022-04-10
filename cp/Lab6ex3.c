#include <stdio.h>

unsigned hex_to_dec(unsigned n){

    if(n <= 9)
        return n;
    return (n%10) + hex_to_dec(n / 10) * 16;
}

int main(void){
    printf("%u\n", hex_to_dec(312));
    return 0;
}