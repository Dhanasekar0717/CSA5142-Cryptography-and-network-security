#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int exists[26] = {0}, k = 0;
    for (int i = 0; key[i] && k < 25; i++) {
        char ch = toupper(key[i] == 'J' ? 'I' : key[i]);
        if (!exists[ch - 'A'] && ch >= 'A' && ch <= 'Z') {
            keyTable[k / SIZE][k % SIZE] = ch;
            exists[ch - 'A'] = 1;
            k++;
        }
    }
    for (char ch = 'A'; k < 25; ch++) {
        if (ch != 'J' && !exists[ch - 'A']) {
            keyTable[k / SIZE][k % SIZE] = ch;
            k++;
        }
    }
}

void encrypt(char *message, char keyTable[SIZE][SIZE]) {
    for (int i = 0; message[i]; i++) message[i] = toupper(message[i] == 'J' ? 'I' : message[i]);
    for (int i = 0; message[i]; i += 2) {
        if (!message[i + 1] || message[i] == message[i + 1]) {
            for (int j = strlen(message) + 1; j > i + 1; j--) message[j] = message[j - 1];
            message[i + 1] = (message[i] == 'X') ? 'Q' : 'X';
        }
        int r1, c1, r2, c2;
        for (int r = 0; r < SIZE; r++) for (int c = 0; c < SIZE; c++) {
            if (keyTable[r][c] == message[i]) r1 = r, c1 = c;
            if (keyTable[r][c] == message[i + 1]) r2 = r, c2 = c;
        }
        if (r1 == r2) message[i] = keyTable[r1][(c1 + 1) % SIZE], message[i + 1] = keyTable[r2][(c2 + 1) % SIZE];
        else if (c1 == c2) message[i] = keyTable[(r1 + 1) % SIZE][c1], message[i + 1] = keyTable[(r2 + 1) % SIZE][c2];
        else message[i] = keyTable[r1][c2], message[i + 1] = keyTable[r2][c1];
    }
}

int main() {
    char key[] = "KEYWORD";
    char message[] = "HELLO WORLD";
    char keyTable[SIZE][SIZE];
    
    generateKeyTable(key, keyTable);
    int j = 0;
    for (int i = 0; message[i]; i++) if (isalpha(message[i])) message[j++] = toupper(message[i]);
    message[j] = '\0';
    
    encrypt(message, keyTable);
    printf("Encrypted message: %s\n", message);
    
    return 0;
}
