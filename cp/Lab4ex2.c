#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_ARR_LEN 16

unsigned get_int(){

    int arr[MAX_ARR_LEN];
    unsigned i = 0;
    char c = getchar();
    if(c != '\n'){
        if(c - '0'){
            while(c != '\n'){
                arr[i] = c - '0';
                ++i;
                c = getchar();
            }
            unsigned n = 0;
            for(int j = 0; j < i; j++)
                n += arr[j] * pow(10 , i-j-1);
            return n;    
        
        }
        if((c = getchar()) == 'x' || c == 'X'){
            
            while((c = getchar()) != '\n'){
                c = toupper(c);
                if (c >= '0' && c <= '9')
                    arr[i] = c - '0';
                else
                    arr[i] = c - '7';
                ++i;
            }

            unsigned n = 0;
            for(int j = 0; j < i; j++)
                n += arr[j] * pow(16 , i-j-1);
            return n;
        }
        while(c != '\n'){
            arr[i] = c - '0';
            ++i;
            c = getchar();
        }
        unsigned n = 0;
        for(int j = 0; j < i; j++)
                n += arr[j] * pow(8 , i-j-1);
        return n;
    }
    return 0;
}

int main(void){

    printf("%u", get_int());
    printf("\n");
   
    return 0;
}