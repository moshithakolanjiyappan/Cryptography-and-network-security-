
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, char *key, char *cipher) {
    int i, j = 0;
    int len = strlen(key);

    for (i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            int shift = tolower(key[j % len]) - 'a';

            cipher[i] = (text[i] - base + shift) % 26 + base;
            j++;
        } else {
            cipher[i] = text[i];
        }
    }

    cipher[i] = '\0';
}

int main() {
    char plaintext[1000], key[100], ciphertext[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%99s", key);

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}
