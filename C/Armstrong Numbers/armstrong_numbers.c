#include "armstrong_numbers.h"

/*
An Armstrong number is a number that is the sum of its own digits 
each raised to the power of the number of digits.

For example:

    9 is an Armstrong number, because 9 = 9^1 = 9
    10 is not an Armstrong number, because 10 != 1^2 + 0^2 = 1
    153 is an Armstrong number, because: 
        153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
    154 is not an Armstrong number, because: 
        154 != 1^3 + 5^3 + 4^3 = 1 + 125 + 64 = 190
*/

int main(int argc, char const *argv[]){   

    // Get integer input
    int candidate;
    printf("Enter an integer: ");
    scanf("%d", &candidate);

    // Run the function to see if the integer given is an 
    // Armstrong number or not
    if (is_armstrong_number(candidate)) {
        printf("True. %d is an Armstrong number.\n", candidate);
    } else {
        printf("False. %d is not an Armstrong number.\n", candidate);
    }
    return 0;
}

/// @brief Determines if a given integer is an Armstrong number 
/// @param candidate 
/// @return true if candidate is an Armstrong number; otherwise false
bool is_armstrong_number(int candidate) {
    int intLen = floor(log10(abs(candidate))) + 1;
    int sum, remainder;
    int digits[intLen];
    int candidateCopy = candidate;

    for (int i = 0; i < intLen; i++) {
        remainder = candidate % 10;
        digits[i] = remainder;
        candidate = floor(candidate / 10);
    }

    for (int i = 0; i < intLen; i++) {
        sum = sum + pow(digits[i], intLen);
    }

    if (sum == candidateCopy) {
        return true;
    } 

    return false;
}
