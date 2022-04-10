#include <stdio.h>
#include <stdlib.h>

FILE* openOutFile(unsigned idx){
    char fileName[100];
    sprintf(fileName, "part_%d.bin", idx);
    printf("We need to open the file %s\n", fileName);
    FILE* f = fopen(fileName, "w");
    return f;
  }

int copyFromTo(FILE* fin, FILE* fout, unsigned nBytes){
    if(!fin || !fout)
       return -1;

  int i = 0;
  int c;
  while((c = fgetc(fin))!= EOF && i<nBytes){
        fputc(c, fout);
        i++;
  }
   return i;
}

int main(int argc, char** argv){

  if(argc != 3){
       printf("Usage: ./a.out fileNameToSplit chunkSize\n");
       return -1;
  }

  char* fileName = argv[1];
  unsigned chSize = atoi(argv[2]);

  printf("We need to split file %s into chunks of %d bytes\n", fileName, chSize);

  FILE* fin = fopen(fileName, "r");
  if(!fin){
      printf("Could not open file\n");
      return -2;
  }
  int i = 0;
  int copiedBytes = 0;
  do{
      i++;
      FILE* fout = openOutFile(i);
      fclose(fout);
      copiedBytes = copyFromTo(fin, fout, chSize);
  }while(copiedBytes == chSize);

  /*FILE* fout = openOutFile(23); 
  int copiedBytes = copyFromTo(fin, fout, chSize);
  if(copiedBytes!=-1){
      printf("We have copied %d bytes \n");
  }
  else{
      printf("Error in coping logic\n");
  } */
      
    return 0;
}