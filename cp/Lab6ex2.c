#include <stdio.h>

unsigned return_digits(unsigned n){
   if(n <= 9){
        if(n % 2 == 0)
            return n;
        else
            return 0;
   }
    if((n%10) % 2 == 0)
        return n%10 + (return_digits(n / 10)) * 10;
    return (return_digits(n / 10));
}

int main(void){
    printf("%u\n", return_digits(123456));
    return 0;
}