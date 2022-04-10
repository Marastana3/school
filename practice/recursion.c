#include <stdio.h>

unsigned factorial(unsigned n)
{
    static int call = 0;
    printf("Call number: %d (n = %u)\n", call, n);
    ++call;
    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {

    printf("%u\n", factorial(5));
    return 0;
}