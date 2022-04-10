#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct aux {
    uint32_t a;
    uint32_t b;
}AUX;

int main(int argc, char **argv) {
 
    FILE *f;

    AUX a;
    uint32_t x = 12345678;
    uint32_t y[5] = {1, 2, 3, 4, 5}; 

    f = fopen("binfile.bin", "wb");
    if(f == NULL) {
        printf("Error open");
        exit(1);
    }

    fwrite(&x, sizeof(uint32_t), 1, f);
    fwrite(&y, sizeof(uint32_t), 5, f);


    fclose(f);
    return 0;
}