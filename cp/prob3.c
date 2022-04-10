#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fields{

    char username[256];
    char shell[256];
    char entry[1024];

}FIELDS;

void swap(FIELDS *x, FIELDS *y){
    FIELDS temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char **argv){

    if(argc != 3)
        exit(EXIT_FAILURE);
    
    unsigned n = atoi(argv[2]);

    FILE *f = fopen(argv[1], "r");
    if(!f)
        exit(EXIT_FAILURE);
    
    FIELDS *arr = malloc(n * sizeof(FIELDS));
    if(!arr)
        exit(EXIT_FAILURE);

    char buff[1024];
    for(int i = 0; i < n; ++i){
        if(!fgets(buff, 1024, f))
            exit(EXIT_FAILURE);

        buff[strlen(buff) - 1] = '\0';
        strcpy(arr[i].entry, buff);

        char *p;
        p = strtok(buff, ":");
        strcpy(arr[i].username, p);

        while(p){
            strcpy(arr[i].shell, p);
            p = strtok(NULL, ":");
        }
    }

    for(int i = 0; i < n-1; ++i)
        for(int j = i + 1; j < n; ++j){
            if(strcmp(arr[i].username, arr[j].username) > 0)
                swap(&arr[i], &arr[j]);
            else if(strcmp(arr[i].username, arr[j].username) == 0 &&
                    strcmp(arr[i].shell, arr[j].shell) > 0)
                    swap(&arr[i], &arr[j]);
        }

    for(int i = 0; i < n; ++i)
        printf("%s\n", arr[i].entry);

    fclose(f);
    return 0;
}