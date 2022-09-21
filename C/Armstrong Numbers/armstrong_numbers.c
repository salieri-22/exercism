#include "armstrong_numbers.h"

int main(int argc, char const *argv[])
{   
    int candidate;
    printf("Enter an integer: ");
    scanf("%d", &candidate);

    if (is_armstrong_number(candidate)) {
        printf("True. %d is an Armstrong number.\n", candidate);
    } else {
        printf("False. %d is not an Armstrong number.\n", candidate);
    }
    return 0;
}


bool is_armstrong_number(int candidate) {
    int intLen = floor(log10(abs(candidate))) + 1;
    int sum, remainder;
    int digits[intLen];
    int candidateCopy = candidate;

    for (int i = 0; i < intLen; i++) {
        remainder = candidate % 10;
        digits[i] = remainder;
        candidate = floor(candidate / 10);
        printf("i = %d\tr = %d, c = %d\n", i, remainder, candidate);
    }

    for (int i = 0; i < intLen; i++) {
        sum = sum + pow(digits[i], intLen);
        printf("sum = %d\n", sum);
    }

    if (sum == candidateCopy) {
        return true;
    } 

    return false;
}
