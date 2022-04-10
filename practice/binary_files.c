#include <stdio.h>

int main() {

    FILE *f = fopen("out", "w");
    if (!f)
        return 1;

    int arr[3] = {1, 2, 3};
    fwrite(&arr, 3, 4, f);
    fclose(f);

    f = fopen("out", "r");
    int arr2[3];
    fread(&arr2, 3, 4, f);
    printf("%d %d %d\n", arr2[0], arr2[1], arr2[2]);


    return 0;
}