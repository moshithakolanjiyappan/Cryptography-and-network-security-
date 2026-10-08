#include <stdio.h>
int main() {
    char s[100];
    int key, i;

    printf("Enter message: ");
    fgets(s, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + key) % 26 + 'A';
        else if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' + key) % 26 + 'a';
    }

    printf("Encrypted text: %s", s);

    return 0;
}
