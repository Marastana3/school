#include <stdio.h>

//ex.2
void suma(unsigned n){
    unsigned sum = 0;
    for(int i = 1; i <= n; ++i){
        sum += i;
    }
    printf("%u\n", sum);
}

//ex.4 sau 3 ca is cam la fel
void patrat(unsigned n){
    if(n > 1){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if( i==1 || i==n || j==1 || j==n){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}

//ex.5
 void cycle(unsigned n, unsigned m){

    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(j > m){
                j = j-m-1;
                break;
            }
        printf("%u ", j);    
        }
    }
    printf("\n");
}

//ex.6
void multiplication(){
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= 10; ++j){
            printf("%u * %u = %u\n", i, j, i*j);
            ++j;
        }
    }
}

//ex.7
unsigned count_odd_digits(long unsigned n){
    unsigned count = 0;
    while(n){
        if((n%10) % 2 == 1)
            ++count;
        n /= 10;
    }
    return count;
}

int main(void){
    printf("%u\n", count_odd_digits(123679));
    return 0;
}