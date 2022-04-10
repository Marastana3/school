#include <stdio.h>

// 0000 0000
// 1010 1001

unsigned char reverse_bits(unsigned char x){
    unsigned char aux = 0;
    for(int i = 0; i < 8; ++i){
        if(x & (1 << i))
            aux |= (1 << (7 - i));
    }
    return aux;
}

unsigned long count_Pairs(unsigned k){
    unsigned char x, y;
    unsigned long count = 0;
    for(int i = 0; i < k; ++i){
        scanf("%hhu %hhu", &x, &y);
        if(x == reverse_bits(y))
            count++;
    }
    return count;
}

int main(void){
    printf("%lu\n", count_Pairs(2));
    return 0;
}