#include <stdio.h>

#define MAX_HEX_LEN 256

void hex_print(unsigned n){
    unsigned r = 0, i = 1;
    unsigned q = n;
    char hex_num[MAX_HEX_LEN] = "";
    while(q){
        r = q % 16;
        if(r < 10)
            r += 48;
        else 
            r += 55;
     hex_num[i++] = r;
     q /= 16;
    }
    for(int j = i -1; j > 0; j--)
        printf("%c", hex_num[j]);
    printf("\n");

}

int main(void){

    hex_print(45);

    return 0;
}