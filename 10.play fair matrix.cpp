#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to generate the Playfair matrix
void generatePlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    int i, j, k = 0;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // Note: 'J' is skipped
    int len = strlen(key);

    // Fill the key in the matrix
    for (i = 0; i < len; i++) {
        if (key[i] != 'J') {
            matrix[k / SIZE][k % SIZE] = key[i];
            alphabet[key[i] - 'A'] = 0; // Mark the letter as used
            k++;
        }
    }

    // Fill the remaining alphabet in the matrix
    for (i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            matrix[k / SIZE][k % SIZE] = alphabet[i];
            k++;
        }
    }
}

// Function to get the position of a character in the Playfair matrix
void getPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a plaintext message using the Playfair cipher
void encryptPlayfair(char *plaintext, char matrix[SIZE][SIZE]) {
    int i, row1, col1, row2, col2;
    int len = strlen(plaintext);

    for (i = 0; i < len; i += 2) {
        getPosition(matrix, plaintext[i], &row1, &col1);
        getPosition(matrix, plaintext[i + 1], &row2, &col2);

        if (row1 == row2) {
            plaintext[i] = matrix[row1][(col1 + 1) % SIZE];
            plaintext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            plaintext[i] = matrix[(row1 + 1) % SIZE][col1];
            plaintext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            plaintext[i] = matrix[row1][col2];
            plaintext[i + 1] = matrix[row2][col1];
        }
    }

    // Add null terminator to the end of the string
    plaintext[len] = '\0';
}

int main() {
    char key[] = "MFHIJKUNOPQZVWXYELARGDSTBC";
    char matrix[SIZE][SIZE];
    char plaintext[] = "MUSTSEEOVERCADOGANWESTCOMINGATONCE";
    
    generatePlayfairMatrix(key, matrix);
    printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (plaintext[i] == ' ') {
            strcpy(&plaintext[i], &plaintext[i + 1]);
            len--;
        }
    }

    encryptPlayfair(plaintext, matrix);
    printf("\nEncrypted message: %s\n", plaintext);

    return 0;
}

