#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char filename[256] = "";
    printf("Enter file name:");
    scanf("%255s", filename);

    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return -1;
    
    char line[256] = "";
    while (!feof(f)) {
        fgets(line, 256, f);
        if (strlen(line) < 4)
            continue;
        for (int i = 0; i < strlen(line) - 3; i++)
            if (isupper(line[i]) && isupper(line[i+1]) 
                && isupper(line[i+2]) && isupper(line[i+3])) {
                printf("%s", line);
                break;
            }
    }

    fclose(f);
    return 0;
}