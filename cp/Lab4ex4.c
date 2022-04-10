#include <stdio.h>
#include <math.h>

unsigned read_number(){

    char c;
    unsigned num = 0 , i = 0 , aux = 0 , j = 0;
    char first_comma = 0;
    while((c = getchar()) != '\n'){
        if(c == ','){
            if(!first_comma)
                first_comma = 1;
            else if(j != 3){
                printf("The number format is wrong!\n");
                return 0;
            }
            j = 0;
            continue;
        }
        num += (c - '0')*pow(10, i++);
        ++j;
    }
    while(num){
        aux = aux*10 + num%10;
        num /= 10;
    }
    return aux;
}


int main(void){

    printf("%u", read_number());
    printf("\n");
    return 0;
}