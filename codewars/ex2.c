#include <stdio.h>

long sum_two_smallest_numbers(size_t n, const int numbers[]){
    int long min1 = 0;
    int long min2 = 0;

    min1 = min2 = numbers[0];

    for(size_t j = 0; j < n; ++j){
        if (numbers[j] < min1) {
            min2 = min1;
            min1 = numbers[j];
        } else if (numbers[j] < min2) {
            min2 = numbers[j];
        }
    }

    return min1 + min2;
}

int main(void){
    const int numbers[] = {15, 28, 4, 2, 43};
    printf("%li\n", sum_two_smallest_numbers(5, numbers));
    return 0;
}