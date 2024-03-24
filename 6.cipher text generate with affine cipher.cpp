#include <stdio.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
void decryptAffineCipher(char *ciphertext, int a, int b) {
    int a_inverse = modInverse(a, ALPHABET_SIZE);
    if (a_inverse == -1) {
        printf("Invalid key\n");
        return;
    }

    printf("Decrypted text: ");
    while (*ciphertext) {
        if (*ciphertext >= 'A' && *ciphertext <= 'Z') {
            int x = (*ciphertext - 'A' - b + ALPHABET_SIZE) % ALPHABET_SIZE;
            int plain = (a_inverse * x) % ALPHABET_SIZE;
            printf("%c", 'A' + plain);
        } else {
            printf("%c", *ciphertext);
        }
        ciphertext++;
    }
    printf("\n");
}
int main() {
    char ciphertext[1000]; 
    int a = 1; // Assume a
    int b;
    b = ('B' - 'E' + ALPHABET_SIZE) % ALPHABET_SIZE;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    decryptAffineCipher(ciphertext, a, b);

    return 0;
}

