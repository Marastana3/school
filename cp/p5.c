#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
        return -1;

    char str1[256] = "";
    char str2[256] = "";
    strcpy(str1, argv[1] + 2);
    strcpy(strchr(str1, '='), "");
    strcpy(str2, strchr(argv[1], '=') + 1);

    FILE *fin = fopen(argv[2], "r");
    if (!fin)
        return -1;
    
    char fileout[256] = "";
    strncpy(fileout, argv[2], 252);
    strcat(fileout, ".pp");
    FILE *fout = fopen(fileout, "w");

    char line[256] = "";
    while (fgets(line, 256, fin)) {
        char *p = NULL;
        char temp[256] = "";
        while ((p = strstr(line, str1))) {
            strcpy(temp, "");
            strncat(temp, line, p - line);
            strcat(temp, str2);
            strcat(temp, p + strlen(str1));
            strncpy(line, temp, 256);
        }
        fprintf(fout, "%s", line);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
