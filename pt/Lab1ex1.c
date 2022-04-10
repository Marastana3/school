#include <stdio.h>
#define MAX_LEN 256

typedef struct point{
        int x, y;
    }PT;

typedef struct triangle{
        PT A, B, C;
    }TR;

typedef struct square{
    PT M, N, P, Q;
    }SQ;

typedef struct circle{
        PT D;
        unsigned radius;
    }CR;

typedef union GeomObj{
    PT point;
    TR triangle;
    SQ square;
    CR circle;
    }GEOM;

int main(void){
    GEOM arr[MAX_LEN] = {0};

    printf("The size of this objec is : %ld bytes\n", sizeof(arr->point));
    printf("The size of the objects : %ld bytes\n", sizeof(union GeomObj));

    return 0;
}