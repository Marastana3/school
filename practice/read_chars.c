#include <stdio.h>

int main() {

    FILE *f = fopen("in.txt", "r");
    if (!f)
        return 1;

    char c;
    while ((c = getc(f)) != EOF) {
        putchar(c);
    }

    return 0;
}