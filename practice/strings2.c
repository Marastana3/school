#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 10
#define MAX_PAIRS 20
#define MAX_BUFF 256

int main(int argc, char **argv){
    if(argc != 2)
        return 1;
    FILE *f = fopen(argv[1], "r");
    if(!f)
        return 69;
    
    char keys[MAX_PAIRS][MAX_LEN];
    char values[MAX_PAIRS][MAX_LEN]; 
    char buff[MAX_BUFF] = "";
    const char sep[] = " =\n";
    unsigned count = 0;

    while(fgets(buff, MAX_BUFF, f)){
        char *key = strtok(buff, sep);
        char *value = strtok(NULL, sep);
        int found = 0;
        for(int i = 0; i < count; ++i){
            if(strcmp(key, keys[i]) == 0){
                strncpy(values[i], value, MAX_LEN);
                found = 1;
                break;
            }
        }
        if(!found){
        strncpy(keys[count], key, MAX_LEN);
        strncpy(values[count], value, MAX_LEN);
        ++count;
        }
    }

    for(int i = 0; i < count - 1; ++i){
        for(int j = i + 1; j < count; ++j){
            if(strcmp(keys[i], keys[j]) > 0){
                char aux[MAX_LEN + 1] = "";
                strcpy(aux, keys[i]);
                strcpy(keys[i], keys[j]);
                strcpy(keys[j], aux); 
            }
        }
    }

    for(int i = 0; i < count; ++i){
        printf("%s = %s\n", keys[i], values[i]);
    }

    fclose(f);
    return 0;
}