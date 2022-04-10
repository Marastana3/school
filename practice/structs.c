#include <stdio.h>

int main() {
    
    struct Vector3
    {
        float x;
        float y;
        float z;
    };

    struct Vector3 v1;
    v1.x = 10;
    v1.y = 11;
    v1.z = -4.41;


    struct Vector3 *pv1 = &v1;
    printf("%f   %f   %f\n", pv1->x, pv1->y, pv1->z);


    printf("\n");
    return 0;
}