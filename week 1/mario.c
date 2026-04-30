#include <cs50.h>
#include <stdio.h>

int get_n(void);

int main(void)
{
    int n = get_n();
    // For rows
    for (int i = 0; i < n; i++)
    {
        // 1. left spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // 2. Left hash
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // 3. Print middle space
        printf("  ");
        // 4. Print Left hash
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_n(void)
{
    int n;
    do
    {
        n = get_int("What's n(Should be between 1-8)? ");
    }
    while (n < 1 || n > 8);
    return n;
}
