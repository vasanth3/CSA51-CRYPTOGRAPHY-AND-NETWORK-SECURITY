#include <stdio.h>

// Function to check if two numbers are coprime
int areCoprime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

// Function to calculate modular inverse of a number
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to encrypt using affine Caesar cipher
char encrypt(char plaintext, int a, int b) {
    if (plaintext >= 'A' && plaintext <= 'Z') {
        return ((a * (plaintext - 'A') + b) % 26) + 'A';
    } else if (plaintext >= 'a' && plaintext <= 'z') {
        return ((a * (plaintext - 'a') + b) % 26) + 'a';
    } else {
        return plaintext;
    }
}

int main() {
    int a, b;
    printf("Enter values of a and b for the affine Caesar cipher: ");
    scanf("%d %d", &a, &b);

    // Check if b is coprime with 26
    if (!areCoprime(b, 26)) {
        printf("Value of b is not coprime with 26. Encryption will not be one-to-one.\n");
        return 1;
    }

    // Check if a is coprime with 26 and not equal to 0
    if (!areCoprime(a, 26) || a == 0) {
        printf("Value of a is not allowed. Encryption will not be one-to-one.\n");
        return 1;
    }

    char plaintext;
    printf("Enter plaintext character: ");
    scanf(" %c", &plaintext);

    char ciphertext = encrypt(plaintext, a, b);
    printf("Ciphertext character: %c\n", ciphertext);

    return 0;
}
