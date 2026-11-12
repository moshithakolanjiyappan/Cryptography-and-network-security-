
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

void generateMatrix(char *key) {
    int alpha[26] = {0};
    int i, k = 0;

    alpha['j' - 'a'] = 1;

    for (i = 0; key[i]; i++) {
        char ch = tolower(key[i]);
        if (ch == 'j') ch = 'i';

        if (isalpha(ch) && !alpha[ch - 'a']) {
            matrix[k / 5][k % 5] = ch;
            alpha[ch - 'a'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!alpha[i]) {
            matrix[k / 5][k % 5] = i + 'a';
            k++;
        }
    }
}

void prepareText(char *input, char *output) {
    int i, j = 0;

    for (i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            char ch = tolower(input[i]);
            output[j++] = (ch == 'j') ? 'i' : ch;
        }
    }

    output[j] = '\0';

    for (i = 0; i < j; i += 2) {
        if (i + 1 < j && output[i] == output[i + 1]) {
            memmove(output + i + 2, output + i + 1, j - i);
            output[i + 1] = 'x';
            j++;
        }
    }

    if (j % 2 != 0) {
        output[j++] = 'x';
        output[j] = '\0';
    }
}

void findPosition(char ch, int *row, int *col) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

void encrypt(char *plaintext, char *ciphertext) {
    int i;

    for (i = 0; plaintext[i]; i += 2) {
        int r1, c1, r2, c2;

        findPosition(plaintext[i], &r1, &c1);
        findPosition(plaintext[i + 1], &r2, &c2);

        if (r1 == r2) {
            ciphertext[i] = matrix[r1][(c1 + 1) % 5];
            ciphertext[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) {
            ciphertext[i] = matrix[(r1 + 1) % 5][c1];
            ciphertext[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else {
            ciphertext[i] = matrix[r1][c2];
            ciphertext[i + 1] = matrix[r2][c1];
        }
    }

    ciphertext[i] = '\0';
}

void printMatrix() {
    printf("\nPlayfair Matrix:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }
}

int main() {
    char key[100], plaintext[1000];
    char formatted[2000], ciphertext[2000];

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter plaintext: ");
    scanf(" %999[^\n]", plaintext);

    generateMatrix(key);
    printMatrix();

    prepareText(plaintext, formatted);
    encrypt(formatted, ciphertext);

    printf("\nFormatted Plaintext: %s\n", formatted);
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    return 0;
}
