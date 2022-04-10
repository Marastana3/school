//Binary Files

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct aux {
    uint32_t a;
    uint32_t b;
}ELF;

int main(int argc, char **argv) {
 
    FILE *f;
    
    ELF elf;

    uint32_t x;
    uint32_t y[5]; 

    f = fopen("binfile.bin", "rb");
    if(f == NULL) {
        printf("Error open");
        exit(1);
    }

    fread(&x, 1, sizeof(uint32_t), f);
    fread(&y, 5, sizeof(uint32_t), f);
    printf("read from file => %d\n", x);


    fclose(f);
    return 0;
}