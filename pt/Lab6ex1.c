#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_LINES 2500

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

int songlength = 0;
SONG songs[2500];
SONG aux1;

int main(int argc, char **argv) 
{
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

    for(int i = 0; i < songlength - 1; i++){
        for(int j = i + 1; j < songlength; ++j){
            if(songs[i].year < songs[j].year){
                
				SONG temp = songs[i];
				songs[i] = songs[j];
				songs[j] = temp;
            }
        }
    }

	for(int i = 0; i < songlength; ++i){
		printf("%d - %s - %d\n", i, songs[i].name, songs[i].year);
	}

    fclose(file);
    return 0;
}