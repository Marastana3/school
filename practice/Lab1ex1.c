#include <stdio.h>
#include <math.h>

unsigned count_digits(unsigned n){
    static unsigned count = 0;
    while(n){
        ++count;
        n /= 10;
    }
    return count;
}

unsigned reverse_number(unsigned n){
    unsigned ogl = 0;
    while(n){
        ogl = ogl*10 + n%10;
        n /= 10;
    }
    return ogl;
}

unsigned base_2_to_10(unsigned n){
    unsigned aux = 0;
    unsigned m = count_digits(n);
    while(n){
        for(int i = 0; i < m; ++i)
            aux += pow(2, i)*(n % 10); 
    n /=10;
    }
    return reverse_number(aux);
}

void base_10_to_2(unsigned n){
    unsigned r = 0;
    printf("The number in base 2 is: ");
    while(n){
      r = n % 2;
      n /= 2; 
      printf("%u", r);
    }
    printf("\n");
}

int main(void){
    printf("The number in base 10 is: %u\n", base_2_to_10(11001001));
    base_10_to_2(123);
    return 0;
}