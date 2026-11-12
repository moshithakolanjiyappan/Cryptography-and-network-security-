
#include <stdio.h>

int main() {
    int p[2][2], c[2][2], inv[2][2], key[2][2];
    int det, i, j;

    printf("Enter plaintext matrix (2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter ciphertext matrix (2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = (p[0][0]*p[1][1] - p[0][1]*p[1][0]) % 26;
    if(det < 0) det += 26;

    int d = -1;
    for(i = 0; i < 26; i++)
        if((det * i) % 26 == 1)
            d = i;

    if(d == -1) {
        printf("Key cannot be found\n");
        return 0;
    }

    inv[0][0] = p[1][1] * d % 26;
    inv[0][1] = -p[0][1] * d % 26;
    inv[1][0] = -p[1][0] * d % 26;
    inv[1][1] = p[0][0] * d % 26;

    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++) {
            inv[i][j] = (inv[i][j] + 26) % 26;
        }

    printf("Recovered Key Matrix:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            key[i][j] = 0;
            for(int k = 0; k < 2; k++)
                key[i][j] += c[i][k] * inv[k][j];

            key[i][j] %= 26;
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }

    return 0;
}
