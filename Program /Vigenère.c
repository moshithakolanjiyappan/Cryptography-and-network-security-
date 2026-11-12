
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], cipher[100];
    int key[100], i, n;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    n = strlen(text);

    printf("Enter %d key values (0-25):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    for(i = 0; i < n; i++) {
        cipher[i] = ((tolower(text[i]) - 'a' + key[i]) % 26) + 'A';
    }

    cipher[n] = '\0';

    printf("Encrypted message: %s\n", cipher);

    return 0;
}
