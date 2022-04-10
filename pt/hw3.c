#include <stdio.h>

int main(int argc, char **argv) {
    int c;
    for(int i = 1; i < argc; ++i){
        FILE *f = fopen(argv[i], "r");
        if(!f)
            continue;
        while((c = fgetc(f)) != EOF){
            if(c == '\n'){
                fputc('\r', stdout);
            }
            fputc(c, stdout);
        }
        fclose(f);
    }
    
    return 0;
}