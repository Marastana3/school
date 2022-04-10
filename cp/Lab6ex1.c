#include <stdio.h>

unsigned return_digit(unsigned n){
    if(n <= 9)
        return n;
    return return_digit(n / 10);

}

int main(void){

    printf("%u\n", return_digit(9678));
    return 0;
}