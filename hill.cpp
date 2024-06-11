#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 3

void encrypt(char message[], int key[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, k;
    int message_len = strlen(message);
    int padded_len = ((message_len + MATRIX_SIZE - 1) / MATRIX_SIZE) * MATRIX_SIZE;
    char encrypted_message[padded_len + 1];

    for (i = 0; i < padded_len; i += MATRIX_SIZE) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            int sum = 0;
            for (k = 0; k < MATRIX_SIZE; k++) {
                int message_char = (i + k < message_len) ? message[i + k] - 'A' : 0;
                sum += key[j][k] * message_char;
            }
            encrypted_message[i + j] = (sum % 26) + 'A';
        }
    }
    encrypted_message[padded_len] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

int main() {
    char message[] = "paymemoremoney";
    int key[MATRIX_SIZE][MATRIX_SIZE] = { { 17,17,5 }, { 21,18,21 }, { 2,2,19} }; // Example key matrix

    printf("Original message: %s\n", message);
    encrypt(message, key);

    return 0;
}
