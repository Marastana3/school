#include <stdio.h>

void print_prime(unsigned num){

    printf("%u = ", num);
    if( num < 2){
        printf("%u ^ 1", num);
        return;
    }
    unsigned d = 2;
    unsigned p = 0;
    while(num % d == 0){
        ++p;
        num /= d;
    }
    if(p)
    printf("%u ^ %u", d, p);
    d = 3;
    p = 0;
    while(num != 1){
        while(num % d == 0){
            ++p;
            num /= d;
        }
        if(p)
            printf(" * %u ^ %u", d, p);
        d += 2;
        p = 0;
    }
    printf("\n");
}

int main(void){

    print_prime(13);

    return 0;
}