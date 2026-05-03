#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    string P1 = get_string("Player 1: ");
    string P2 = get_string("Player 2: ");
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int sumP1 = 0;
    for (int i = 0, n1 = strlen(P1); i < n1; i++)
    {
        if (isalpha(P1[i]))
        {
            sumP1 += points[toupper(P1[i]) - 'A'];
        }
    }

    int sumP2 = 0;
    for (int i = 0, n2 = strlen(P2); i < n2; i++)
    {
        if (isalpha(P2[i]))
        {
            sumP2 += points[toupper(P2[i]) - 'A'];
        }
    }

    if (sumP2 < sumP1)
    {
        printf("Player 1 wins\n");
    }
    else if (sumP2 > sumP1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie\n");
    }
}
