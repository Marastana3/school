#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 256

int main(int argc, char **argv){
    if(argc != 3)
        exit(EXIT_FAILURE);
    FILE *f = fopen(argv[1] ,"r");
    int seconds = atoi(argv[2]);
    
    const char tags[3][4] = {"<i>", "<b>", "<u>"};
    const char closing_tags[3][5] = {"</i>", "</b>", "</u>"};
    char buff[MAX_BUFF] = "";
    int line = 0;
    int s[2];
    int m[2];
    int h[2];
    while (fgets(buff, MAX_BUFF, f)) {
        ++line;
        switch (line) {
            case 1:
                printf("%s", buff);
                break;
            case 2:  
                sscanf(buff, "%d:%d:%d --> %d:%d:%d\n", &h[0], &m[0], &s[0], &h[1], &m[1], &s[1]);
                for (int i = 0; i < 2; ++i) {
                    s[i] += seconds;
                    m[i] += (s[i] / 60);
                    s[i] %= 60;
                    h[i] += (m[i] / 60);
                    m[i] %= 60;
                }
                printf("%d:%d:%d --> %d:%d:%d\n", h[0], m[0], s[0], h[1], m[1], s[1]);
                break;
            case 3:
                do {
                    char *p, *q;
                    for (int i = 0; i < 3; ++i) {
                        p = strstr(buff, tags[i]);
                        if (p)
                            break;
                    }
                    for (int i = 0; i < 3; ++i) {
                        q = strstr(buff, closing_tags[i]);
                        if (q)
                            break;
                    }
                    if (p) {
                        strcpy(buff, buff + 3);
                    }
                    if (q) {
                        q[1] = '\0';
                        q[0] = '\n';
                    }
                    printf("%s", buff);
                } while (fgets(buff, MAX_BUFF, f) && strcmp(buff, "\n") != 0);
                line = 0;
                break;
        }
    }

    fclose(f);
    return 0;
}