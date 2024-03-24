#include <stdio.h>
#include <string.h>
void encrypt(char *plaintext, char *key) {
    int i;
    int len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = key[plaintext[i] - 'a'];
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = key[plaintext[i] - 'A'] - ('a' - 'A');
        }
    }
}

int main() {
    char plaintext[100];
    char key[52];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    
    printf("Original message: %s\n", plaintext);
    encrypt(plaintext, key);
    printf("Encrypted message: %s\n", plaintext);
    
    return 0;
}
