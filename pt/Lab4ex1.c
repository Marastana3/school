#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song
{
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

int main(int argc, char **argv) 
{
	if (argc != 3)
	{
		printf("Error no of args\n");
		exit(2);
	}

	char filename[100];
	strcpy(filename, argv[1]);

	int year = atoi(argv[2]);

	printf("Read from args: f=%s, y=%d\n", filename, year);

	FILE *file = fopen(filename, "r");
	if (file == NULL) 
	{
		printf("ERROR FILE!\n");
		exit(2);
	}

	while(!feof(file))
	{
		char *line = (char *)malloc(1000);
		if (line == NULL)
		{
			printf("ERROR malloc");
			exit(2);
		}

		if (fgets(line, 1000, file) == NULL)
		{
			continue;
		}

		line[strlen(line) - 1] = 0;

		// printf("%s\n", line);
		char *t = NULL;

        if (line[0] == '\"')
            t = strtok(line, "\"");
        else
            t = strtok(line, ",");
		
		SONG aux;
		int index = 0;
		while (t != NULL)
		{
			// printf("%s\n", t);
			
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

	fclose(file);

	for(int i = 0; i < songlength; i++)
	{
		if (year == songs[i].year) 
		{
			printf("%d - %s - %d\n", i, songs[i].name, songs[i].year);
		}
	}

	return 1;
}