#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Incorrect Command-line argments\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Incorrect Command-line argments\n");
        return 1;
    }

    for ( int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only letters\n");
            return 1;
        }
    }

    int seen[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        int index = toupper(argv[1][i]) - 'A';
        if (seen[index] == 1)
        {
            printf("Key must not have duplicate letters\n");
            return 1;
        }
        seen[index] = 1;
    }

    string plaintext = get_string("PlainText: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 'A';
                printf("%c", toupper(argv[1][index]));
            }
            else
            {
                int index = plaintext[i] - 'a';
                printf("%c", tolower(argv[1][index]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
