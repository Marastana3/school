#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

unsigned count_words(char *str)
{
    static const char sep[] = " \t,.:;!?\v";
    unsigned words = 0;
    char *p = strtok(str, sep);
    while (p) {
        ++words;
        p = strtok(NULL, sep);
    }
    return words;
}

int main(void){
    freopen("file2.txt", "r", stdin);
    char buf[MAX_LINE_LENGTH] = "";
    unsigned words = 0, lines = 0, pcount = 1;

    while (fgets(buf, MAX_LINE_LENGTH, stdin)) {
        if (strcmp(buf, "\n") == 0) {
            printf("Paragraph %u: %u lines, %u words\n", pcount, lines, words);
            ++pcount;
            lines = 0;
            words = 0;
            continue;
        }
        ++lines;
        words += count_words(buf);
    }
    printf("Paragraph %u: %u lines, %u words\n", pcount, lines, words);
    return 0;
}