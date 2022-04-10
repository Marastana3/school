#include <stdio.h>
#include <stdlib.h>


int main() {

    struct MyStruct
    {
        int x;
        char str[256];
        float y;
    };

    struct MyStruct* ms = (struct MyStruct*) malloc(sizeof(struct MyStruct));
    return 0;
}