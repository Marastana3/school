#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ignore_whitespace(){
    char c;
    while((c = getchar()) != EOF && isspace(c));
    return c;
}

int read_chars(){
    char c = ignore_whitespace();

    if(c != '_' && !isalpha(c))
        return 0;  

    while((c = getchar()) != EOF && !isspace(c) && c != '=') {
        if(!isalnum(c) && c != '_')
            return 0;
    }

    if (isspace(c))
        c = ignore_whitespace();

    if(c != '=')
        return 0;

    c = ignore_whitespace();
    if(c != '[')
        return 0;

    char temp;
    while((c = ignore_whitespace()) != EOF){

        if(c != '-' && !isdigit(c))
            return 0;

        while((c = getchar()) != EOF && !isspace(c) && c != ',' && c != ']'){
            if(!isdigit(c))
                return 0;
        }

        if(isspace(c)){
            c = ignore_whitespace();
            if(c != ',' && c != ']')
                return 0;
        }

        temp = c;

        if(c == ']'){
            c = ignore_whitespace();
            if(c != EOF)
                return 0;
        } 
    }
    if(temp != ']')
        return 0;

    return 1;
}

int main(void){
    if(read_chars())
        printf("DA\n");
    else printf("NUUUUUUUUUUU\n");
    return 0;
}