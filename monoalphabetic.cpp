#include <stdio.h>

void encrypt(char *plaintext, char *key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            plaintext[i] = key[plaintext[i] - 'a'];
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[i] = key[plaintext[i] - 'A'] + ('a' - 'A');
    }
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            for (j = 0; j < 26; j++) {
                if (key[j] == ciphertext[i]) {
                    ciphertext[i] = 'a' + j;
                    break;
                }
            }
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            for (j = 0; j < 26; j++) {
                if (key[j] == ciphertext[i] + ('a' - 'A')) {
                    ciphertext[i] = 'A' + j;
                    break;
                }
            }
        }
    }
}

int main() {
    char plaintext[100], key[26];
    int i;

    printf("Enter plaintext: ");
    gets(plaintext); 

    printf("Enter key (a 26-character string with unique alphabets): ");
    gets(key); 
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);

    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
