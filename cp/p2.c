#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        return -1;
    }

    FILE *f = fopen(argv[2], "r");
    if (f == NULL)
        return -1;
    
    char line[256] = "", line2[256] = "";
    char *p = NULL;
    const char whitespace[] = " \t\n\f\r\v";
    while (!feof(f)) {
        fgets(line, 256, f);
        strcpy(line2, line);

        p = strtok(line, whitespace);
        while (p != NULL) {
            if (strcmp(p, argv[1]) == 0) {
                printf("%s", line2);
                break;
            }
            p = strtok(NULL, whitespace);
        }
    }

    fclose(f);
    printf("\n");
    return 0;
}