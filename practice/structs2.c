#include <stdio.h>

int main() {
    
    typedef struct MyStruct
    {
        float x;
        float y;
        char c;
    }MS;

    MS s1;
    struct MyStruct s2;
    

    printf("%d\n", sizeof(struct MyStruct));


    printf("\n");
    return 0;
}