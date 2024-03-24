#include <stdio.h>
#include <math.h>

#define ALPHABET_SIZE 25
double calculatePossibleKeys() {
    double possibleKeys = 1;
    int i;
    for (i = 1; i <= ALPHABET_SIZE; i++) {
        possibleKeys *= i;
    }
    return log2(possibleKeys);
}

int main() {
    double keys = calculatePossibleKeys();
    printf("Approximate number of possible keys: %.0lf\n", pow(2, keys));
    
    return 0;
}
