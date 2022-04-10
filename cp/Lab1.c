#include <stdio.h>
#include <math.h>

unsigned swapLMD(unsigned n)
{
    return (n%10) * 100 + ((n/10) % 10) * 10 + (n / 100);
}

void addTime(unsigned h, unsigned m,unsigned dMin)
{
    m += dMin;
    h += m/60;
    m %= 60;

    printf("Hour : %u, Min : %u\n", h, m);
}

void Swap(unsigned *x, unsigned *y){
      
      unsigned aux = *x;
      *x = *y;
      *y = aux;
}

unsigned Median(unsigned x, unsigned y, unsigned z){

   if(x > y)
        Swap(&x,&y);
   if(y > z)
        Swap(&y,&z);
   if(x > y)
        Swap(&x,&y);
   return y;
}

int func(int x, int y, int z){

    return (x!=y)+(x!=z)+(y!=z);

}

double myround(double x){

    if(x >= ((int)x) + 0.5)
        return ceil(x);
    return floor(x);
    
}

int main(void){

    printf("%f\n", myround(3.14));
    
    return 0;
}