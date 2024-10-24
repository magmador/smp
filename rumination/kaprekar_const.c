#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define KAPREKAR_CONST_VAL 6174
#define KAPREKAR_CAPACITY 4
#define MIN_4_DIGIT 1000
#define MAX_4_DIGIT 9999

static void digits_to_number(int *const digits, int *number, const int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        *number = *number * 10 + digits[i];
    }
}

static void number_to_digits(int number, int *const digits, const int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        digits[i] = number % 10;
        number /= 10;
    }
}

static bool are_digits_in_number_unique(const int number)
{
    bool is_unique = true;
    int digits[KAPREKAR_CAPACITY] = {0};

    number_to_digits(number, digits, KAPREKAR_CAPACITY);

    for (int i = 0; i < KAPREKAR_CAPACITY; i++)
    {
        for (int j = i + 1; j < KAPREKAR_CAPACITY; j++)
        {
            if (digits[i] == digits[j])
            {
                is_unique = false;
            }
        }
    }

    return is_unique;
}

static void sort_digits(const bool is_ascend, int *const digits, const int capacity)
{
    for (int i = capacity - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (is_ascend ? digits[j] > digits[j + 1] : digits[j] < digits[j + 1])
            {
                digits[j] = digits[j] + digits[j + 1];
                digits[j + 1] = digits[j] - digits[j + 1];
                digits[j] = digits[j] - digits[j + 1];
            }
        }
    }
}

static int order_number(int number, const bool is_ascend)
{
    int sorted_number = 0;
    int digits[KAPREKAR_CAPACITY] = {0};

    number_to_digits(number, digits, KAPREKAR_CAPACITY);
    sort_digits(is_ascend, digits, KAPREKAR_CAPACITY);
    digits_to_number(digits, &sorted_number, KAPREKAR_CAPACITY);

    return sorted_number;
}

static bool is_number_kaprekar(int number)
{
    int s_number = 0;
    int m_number = 0;
    bool is_kaprekar = false;
    int iterations_number = 0;

    if (!are_digits_in_number_unique(number))
    {
        // All digits in Kaprekar constant should be unique
        return false;
    }

    while (number != KAPREKAR_CONST_VAL && number > 0)
    {
        m_number = order_number(number, false);
        s_number = order_number(number, true);

        number = m_number - s_number;
        iterations_number++;
    }

    is_kaprekar = number == KAPREKAR_CONST_VAL;

    return is_kaprekar;
}

int main()
{
    for (int i = MIN_4_DIGIT; i < MAX_4_DIGIT; i++)
    {
        if (is_number_kaprekar(i))
        {
            printf("%d ", i);
            continue;
        }
    }
    printf("\n");

    return 0;
}
