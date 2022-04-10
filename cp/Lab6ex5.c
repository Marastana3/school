#include <stdio.h>
#include <math.h>

#define PRECISION 1e-6

unsigned fact(unsigned n){
    if(n < 2)
        return 1;
    return n * fact(n - 1);
}

double expo(double x, double sum, unsigned n, double term){
    term = pow(x, n) / fact(n);
    sum += term;
    if(term < PRECISION)
        return sum;
    return expo(x, sum, n + 1, term);

}

int main(void){

    printf("%lf\n", expo(5, 0, 0, 0));
    return 0;
}