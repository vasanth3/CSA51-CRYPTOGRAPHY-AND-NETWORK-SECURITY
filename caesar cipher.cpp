#include <stdio.h>
#include <string.h>
void caesarCipher(char message[], int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    printf("Encrypted message: %s\n", message);
}

int main() {
    char message[100];
    int key, i;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    caesarCipher(message, key);

    return 0;
}
