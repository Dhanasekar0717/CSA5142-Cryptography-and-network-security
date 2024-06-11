#include <stdio.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

void affineCaesarCipher(int a, int b, char plaintext[]) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            int p = plaintext[i] - 'A';
            int ciphertext = (a * p + b) % 26;
            printf("%c", 'A' + ciphertext);
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            int p = plaintext[i] - 'a';
            int ciphertext = (a * p + b) % 26;
            printf("%c", 'a' + ciphertext);
        } else {
            printf("%c", plaintext[i]);
        }
        i++;
    }
}

int main() {
    int a, b;
    char plaintext[100];

    printf("Enter the value of a: ");
    scanf("%d", &a);

    // Check if 'a' is allowed
    if (a % 2 == 0 || a % 13 == 0) {
        printf("Value of a is not allowed.\n");
        return 0;
    }

    printf("Enter the value of b: ");
    scanf("%d", &b);

    if (b < 0 || b >= 26) {
        printf("Value of b should be between 0 and 25.\n");
        return 0;
    }

    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);

    affineCaesarCipher(a, b, plaintext);
}
