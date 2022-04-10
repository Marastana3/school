#include <stdio.h>

//ex.1
void print_shape(unsigned n){
if(n%2 == 1){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if( i==1 || i==n || j==1 || j==n || i==(n/2) + 1)
                    printf("* ");
                else
                    printf("  ");
            }
            printf("\n");
        }
    }
    else
        printf("The chosen number is NOT ODD!\n");
}

//ex.2
unsigned max_of_3(unsigned x, unsigned y, unsigned z){
    unsigned max = 0;
    if(x > max){
        max = x;
        if(y > max)
            max = y;
    }
    if(z > max)
        max = z;
    return max;
}

int main(void){
    
    printf("The max is: %u\n", max_of_3(2005,1024,456));
    return 0;
}