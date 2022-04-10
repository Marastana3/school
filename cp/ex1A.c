#include <stdio.h>
#include <math.h>

#define MAX_N (pow(2 , 32) - 1)

unsigned long long sum_digits(unsigned long n){
    if(n <= 9)
        return n;
    return (n%10) + sum_digits(n/10);
}

unsigned max_digit(unsigned long n){
    unsigned max = 0;
    while(n){
        if((n%10) > max)
            max = n%10;
        n /= 10;
    }
    return max;
}

unsigned long reverse_digits(unsigned long n){
    unsigned long ogl = 0;
    while(n){
        ogl = ogl*10 + (n%10);
        n /= 10;
    }
    return ogl;
}

void print_numbers(unsigned k, unsigned long n){
    const unsigned long max_n = MAX_N;

    for(int i = 0; i < k; ++i){
        unsigned long aux = n;
        unsigned max_d = max_digit(n);
        for(int j = i; j < k; ++j){
            if((aux*10 + max_d) > max_n)
                break;
            aux = aux*10 + max_d;
            printf("%lu\n", aux);
        }
        for(int j = 0; j < i; ++j){
            unsigned long sum = reverse_digits(sum_digits(aux));
            while(sum){
                if((aux*10 + sum % 10) > max_n)
                    goto EXIT_LOOPS;
                aux = aux*10 + sum%10;
                sum /= 10;
            }
            printf("%lu\n", aux);
        }
        EXIT_LOOPS:; 
    }
}

int main(void){

    print_numbers(3, 123);
    return 0;
}