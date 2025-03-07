#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void decrypt(char *ciphertext, int shift) {
 int length = strlen(ciphertext);
 int i;
 for ( i = 0; i < length; i++) {
 if (isalpha(ciphertext[i])) {
 if (isupper(ciphertext[i])) {
 ciphertext[i] = 'A' + (ciphertext[i] - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
} else {
 ciphertext[i] = 'a' + (ciphertext[i] - 'a' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
 }
 }
 }
}
void countLetterFrequency(char *text, int *frequency) {
 int length = strlen(text);
 int i;
 
 for (i = 0; i < length; i++) {
 if (isalpha(text[i])) {
 if (isupper(text[i])) {
 frequency[text[i] - 'A']++;
 } else {
 frequency[text[i] - 'a']++;
 }
 }
 }
}
// Function to find the shift value with the maximum frequency match
int findShiftValue(int *frequency) {
 int maxFrequency = 0;
 int shift = 0;
 int i;
 for ( i = 0; i < ALPHABET_SIZE; i++) {
 if (frequency[i] > maxFrequency) {
 maxFrequency = frequency[i];
shift = (ALPHABET_SIZE - i) % ALPHABET_SIZE;
 }
 }
 
 return shift;
}
int main() {
 char ciphertext[1000];
 printf("Enter the ciphertext: ");
 fgets(ciphertext, sizeof(ciphertext), stdin);
 int i;
 
 int letterFrequency[ALPHABET_SIZE] = {0};
 countLetterFrequency(ciphertext, letterFrequency);
 
 int shift = findShiftValue(letterFrequency);
 
 printf("Possible plaintexts in order of likelihood:\n");
 for (i = 0; i < 10; i++) {
 decrypt(ciphertext, shift);
 printf("%d. %s\n", i + 1, ciphertext);
 }
return 0; 
 }
