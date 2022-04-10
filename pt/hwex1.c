#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct song {
        char name[100];
        char author[100];
        int year;
        char fn[200];
        int i1;
        int i2;
        int i3;
        int i4;
} SONG;

void swap(SONG *x, SONG *y){
    SONG temp = *x;
    *x = *y;
    *y = temp;
}

void print(SONG *arr, int n){
    for(int i = 0; i < n; ++i)
        printf("%d - %s - %d\n", i, arr[i].name, arr[i].year);
}

// quick sort
int pivot_qs(SONG *arr, int low, int high){
    SONG pivot[2500];
    pivot->year = arr[high].year;
    int i = low - 1;

    for(int j = low; j <= high - 1; ++j){
        if(arr[j].year < pivot->year){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(SONG *arr, int low, int high){
    if(low < high){
        int index = pivot_qs(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}

//bubble sort

void bubble_sort(SONG *arr, int n){

    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j){
            if(arr[i].year > arr[j].year)
                swap(&arr[i], &arr[j]);
        }
}

int songlength = 0;
SONG songs[2500];

int main(int argc, char **argv){

    if (argc != 2)
	{
		printf("Error no of args\n");
		exit(EXIT_FAILURE);
	}

	char filename[100];
	strcpy(filename, argv[1]);

	printf("Read from args: f=%s\n", filename);

	FILE *file = fopen(filename, "r");
	if (file == NULL) 
	{
		printf("ERROR FILE!\n");
		exit(EXIT_FAILURE);
	}

	while(!feof(file))
	{
		char *line = (char *)malloc(2500);
		if (line == NULL)
		{
			printf("ERROR MALLOC!\n");
			exit(EXIT_FAILURE);
		}

		if (fgets(line, 2500, file) == NULL)
		{
			continue;
		}

		line[strlen(line) - 1] = 0;

		char *t = NULL;

        if (line[0] == '\"')
            t = strtok(line, "\"");
        else
            t = strtok(line, ",");
		
		SONG aux;
		int index = 0;
		while (t != NULL)
		{
			
			switch(index)
			{
				case 0:
					strcpy(aux.name, t);
					break;
				case 1:
					strcpy(aux.author, t);
					break;
				case 2:
					aux.year = atoi(t);
					break;
				case 3:
					strcpy(aux.fn, t);
					break;
				case 4:
					aux.i1 = atoi(t);
					break;
                case 5:
                    aux.i2 = atoi(t);
                    break;
                case 6:
                    aux.i3 = atoi(t);
                    break;
                case 7:
                    aux.i4 = atoi(t);
                    break;
			}

            if (index == 2)
                t = strtok(NULL, "\"");
            else
			    t = strtok(NULL, ",");
			
			index++;
		}	

		songs[songlength++] = aux;	
		free(line);			
	}
    clock_t start = clock();
    for(int i = 0; i < songlength; ++i){
        quick_sort(songs, 0, songlength - 1);
        //bubble_sort(songs, songlength);
    }
    clock_t end = clock();

    clock_t total = (double)(end - start);

    print(songs, songlength);
    printf("Time : %ld", total);    
    return 0;
}