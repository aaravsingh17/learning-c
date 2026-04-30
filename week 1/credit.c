#include <cs50.h>
#include <stdio.h>

bool n_is_valid(long n);
int count_digits(long n);
long get_first_two(long n);
string card_type(long n);
bool luhn(long n);

int main(void)
{
    long n = get_long("Number: ");
    if (n_is_valid(n) == false)
    {
        printf("INVALID\n");
        return 0;
    }

    if (!luhn(n))
    {
        printf("INVALID\n");
        return 0;
    }

    printf("%s\n", card_type(n));
}

bool n_is_valid(long n)
{
    if (n <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int count_digits(long n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

long get_first_two(long n)
{
    long first_two = n;
    while (first_two >= 100)
    {
        first_two = first_two / 10;
    }
    return first_two;
}

string card_type(long n)
{
    int count = count_digits(n);
    long first_two = get_first_two(n);

    if (count == 15)
    {
       if (first_two == 34 || first_two == 37)
       {
        return "AMEX";
       }
       else
       {
        return "INVALID";
       }
    }
    else if (count == 16 && (first_two >= 51 && first_two <= 55))
    {
        return "MASTERCARD";
    }
    else if (count == 16 || count == 13)
    {
        int new_first_two = first_two / 10;
        if (new_first_two == 4)
        {
             return "VISA";
         }
        else
        {
             return "INVALID";
         }
     }
     else
     {
        return "INVALID";
     }
}

bool luhn(long n)
{
    long temp = n;
    int sum_odd = 0;
    int sum_even = 0;
    while (temp > 0)
    {
        int odd_digit = temp % 10;
        temp = temp / 10;
        int even_digit = (temp % 10) * 2;
        temp = temp / 10;
        sum_odd = sum_odd+ odd_digit;
        int digit = 0;
        if (even_digit >= 10)
        {
            digit = (even_digit / 10) + (even_digit % 10);
        }
        else
        {
            digit = even_digit;
        }
        sum_even = sum_even + digit;
    }
    return (sum_odd + sum_even) % 10 == 0;
}
