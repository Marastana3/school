#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 4)
        return -1;

    unsigned m = atoi(argv[1]);
    unsigned n = atoi(argv[2]);
    const char *filename = argv[3];

    FILE *f = fopen(filename, "r");
    if (!f)
        return -1;

    char line[256] = "";
    while (fgets(line, 256, f)) {
        line[strlen(line) - 1] = '\0';
        char *p = strtok(line, ",");
        int i = 0;
        while (p) {
            if (i > n)
                break;
            if (i >= m && i <= n)
                printf("%s ", p);
            ++i;
            p = strtok(NULL, ",");
        }
        printf("\n");
    }
    
    printf("\n");
    fclose(f);
    return 0;
}