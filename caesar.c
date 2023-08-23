#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    char *s = argv[1];
    for (int j = 0; j < strlen(s); j++)
    {
        char nu = s[j];
        if (!isdigit(nu))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(s);
    char text[50];
    printf("plaintext: ");
    scanf("%s",text);
    char *c = text;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] -= 65;
                c[i] = (text[i] + key) % 26;
                c[i] += 65;
            }
            if (islower(text[i]))
            {
                text[i] -= 97;
                c[i] = (text[i] + key) % 26;
                c[i] += 97;
            }
        }
    }
    printf("ciphertext: %s\n", c);
}
