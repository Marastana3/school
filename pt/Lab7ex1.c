#include <stdio.h>

char *arr0_19[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                "eighteen", "nineteen"};

char *arr20_90[20] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void ang0_19(int n){
    if(n >= 0 && n <= 19)
        printf(" %s ", arr0_19[n]);
}

void ang20_99(int n){
    int fd = n/10;
    int sd = n%10;

    printf(" %s ", arr20_90[fd - 2]);
    if(sd != 0)
        ang0_19(sd);
}

void ang100_999(int n){
    int fd = n/100;
    int sd = (n/10)%10;
    int td = n%10;

    if(fd != 0){
        ang0_19(fd);
        printf("hundred ");
    }
    if(sd == 0 && td > 0)
        ang0_19(td);
    if(sd >1 && td > 0)
        ang20_99(sd*10 + td);
    if(sd > 1 && td == 0)
        ang20_99(sd*10);
    if(sd == 1 && td > 0)
        ang0_19(sd*10 + td);
    if(sd == 1 && td == 0)
        ang0_19(sd*10);

}

void ang1000_9999(int n){
    int fd = n/1000;
    int sd = (n/100)%10;
    int td = (n/10)%10;
    int f4d = n%10;

    ang0_19(fd);
    printf("thousand ");

    if(sd > 1 && td > 1 && f4d >= 0)
        ang100_999(sd * 100 + td * 10 + f4d);
    if(sd > 1 && td == 0 && f4d >= 0)
        ang100_999(sd*100 + f4d);
    if(sd == 0 && td > 1 && f4d >= 0)
        ang20_99(td * 10 + f4d);
    if(sd == 0 && td == 1 && f4d >= 0)
        ang0_19(td*10 + f4d);
    if(sd == 0 && td == 0 && f4d > 0)
        ang0_19(f4d);
    if(sd == 1 && td > 1 && f4d >= 0)
        ang100_999(sd*100 + td*10 + f4d);
    if(sd == 1 && td == 0 && f4d == 0)
        ang100_999(sd*100);
    if(sd == 1 && td == 0 && f4d > 0)
        ang100_999(sd * 100 + f4d);
    if(sd == 1 && td == 1 && f4d >= 1)
        ang100_999(sd*100 + td*10 + f4d);
}

void ang10000_99999(int n){
    int fd = n/10000;
    int sd = (n/1000)%10;
    int td = (n/100)%10;
    int f4d = (n/10)%10;
    int f5d = n%10;

    if(fd == 1 && sd >= 0){
        ang0_19(fd*10 + sd);
        printf(" thousand");
    }

    if(fd > 1 && sd >= 0){
        ang20_99(fd*10 + sd);
        printf(" thousand");
    }

    if(td > 1 && f4d >= 1 && f5d >= 0)
        ang100_999(td * 100 + f4d * 10 + f5d);
    if(td > 1 && f4d == 0 && f5d >= 0)
        ang100_999(td*100 + f5d);
    if(td == 0 && f4d > 1 && f5d >= 0)
        ang20_99(f4d * 10 + f5d);
    if(td == 0 && f4d == 1 && f5d >= 0)
        ang0_19(f4d*10 + f5d);
    if(td == 0 && f4d == 0 && f5d > 0)
        ang0_19(f5d);
    if(td == 1 && f4d > 1 && f5d >= 0)
        ang100_999(td*100 + f4d*10 + f5d);
    if(td == 1 && f4d == 0 && f5d == 0)
        ang100_999(td*100);
    if(td == 1 && f4d == 0 && f5d > 0)
        ang100_999(td * 100 + f5d);
    if(td == 1 && f4d == 1 && f5d >= 1)
        ang100_999(td*100 + f4d*10 + f5d);
    
}

void ang100000_999999(int n){
    int fd = n/100000;
    int sd = (n/10000)%10;
    int td = (n/1000)%10;
    int f4d = (n/100)%10;
    int f5d = (n/10)%10;
    int f6d = n%10;

    if(fd >= 1 && sd >= 0 && td >= 0){
        ang100_999(fd*100 + sd*10 + td);
        printf(" thousand ");
    }

    if(f4d > 1 && f5d >= 1 && f6d >= 0)
        ang100_999(f4d * 100 + f5d * 10 + f6d);
    if(f4d > 1 && f5d == 0 && f6d >= 0)
        ang100_999(f4d*100 + f6d);
    if(f4d == 0 && f5d > 1 && f6d >= 0)
        ang20_99(f5d * 10 + f6d);
    if(f4d == 0 && f5d == 1 && f6d >= 0)
        ang0_19(f5d*10 + f6d);
    if(f4d == 0 && f5d == 0 && f6d > 0)
        ang0_19(f6d);
    if(f4d == 1 && f5d > 1 && f6d >= 0)
        ang100_999(f4d*100 + f5d*10 + f6d);
    if(f4d == 1 && f5d == 0 && f6d == 0)
        ang100_999(f4d*100);
    if(f4d == 1 && f5d == 0 && f6d > 0)
        ang100_999(f4d * 100 + f6d);
    if(f4d == 1 && f5d == 1 && f6d >= 1)
        ang100_999(f4d*100 + f5d*10 + f6d);

}

int main(void){
    int n;

    printf("Please type a number (from 0 to 999999) : ");
    scanf("%d", &n);

    if(n >= 0 && n <= 19){
        printf("%d - ", n);
        ang0_19(n);
    }
        
    if(n >= 20 && n <= 99){
        printf("%d - ", n);
        ang20_99(n);
    }
        

    if(n >= 100 && n <= 999){
        printf("%d - ", n);
        ang100_999(n);
    }
    if(n >= 1000 && n <= 9999){
        printf("%d - ", n);
        ang1000_9999(n);
    }

    if(n >= 10000 && n <= 99999){
        printf("%d - ", n);
        ang10000_99999(n);
    }

    if(n >= 100000 && n <= 999999){
        printf("%d - ", n);
        ang100000_999999(n);
    }

    printf("\n");
    return 0;
}