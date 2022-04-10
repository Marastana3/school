#include <stdio.h>

/* 
    if(num & (1 << i)) -> check i-th bit
    num |= (1 << i) -> set i-th bit
    num &= ~(1 << i) -> unset i-th bit
*/

static const int SIZE = 32;

void print_binary(unsigned n) {
    int j = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        if (n & (1 << i))
            printf("1");
        else
            printf("0");
        if (++j == 4) {
            printf(" ");
            j = 0;
        }
    }
    printf("\n");
}

unsigned nibbles_a(unsigned n) {
    unsigned x = 0;
    for (int i = SIZE - 1; i >= SIZE/2; i -= 4) {
        for (int j = 0; j < 4; ++j) {
            if (n & (1 << (i - j)))
                x |= (1 << (SIZE - i - 1 + (3 - j)));
            if (n & (1 << (SIZE - i - 1 + (3 - j))))
                x |= (1 << (i - j));
        }
    }
    return x;
}

unsigned nibbles_b(unsigned n) {

}

int main(void){

    print_binary(nibbles_a(0b01010000111011111010110000011101));
    print_binary(nibbles_a(0b11010101111111110010000110101001));
    return 0;
}