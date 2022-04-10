/*1 Splitting into words: Write a function that splits a string into words (strings with no whitespace), 
returning a (dynamically allocated) array of pointers to (dynamically allocated) copies of the words in the string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanup(char** words, int num_of_words){
  
  //free the memory for each word
   for(int i = 0; i < num_of_words; ++i)
     free(words[i]);

  //free the memory for the array of pointers
   free(words);

}


char **split_string(char *s, int *words_count){
    
    //backup given string
    char *str = (char*) malloc(strlen(s) + 1);
    strcpy(str, s);

    char whitespace[] ="\t\n\f\r\v";
    char **words = NULL;
    int num_of_words = 0;

    //separate the string into words
    char *p = strtok(str, whitespace);

    while(p){
        //realocate array for each new word
        ++num_of_words;
    }

}

int main(void){
    
    char str[] = "hello world welcome back";

    return 0;
}