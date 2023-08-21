#include "main.h"
#define BUFFER_SIZE 1024

/**
 * _printf - takes strings and arguments of each '%'
 * @format: the first string containing '%'
 * @...: list of arguments variable
 * Return: the total of character printed
*/

int print_positive_int(int value);

void print_buffer(char buffer[], int *buff_ind);


int _printf(const char *format, ...)
{
    va_list args;
    int char_count = 0;
    int printed_chars = 0;
    int buff_index = 0;
    char char_buffer[BUFFER_SIZE];

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == '%')
            {
                char_buffer[buff_index++] = '%';
                if (buff_index == BUFFER_SIZE)
                {
                    print_buffer(char_buffer, &buff_index);
                    char_count += buff_index;
                }
            }
            else if (*format == 'c')
            {
                int ch = va_arg(args, int);
                char_buffer[buff_index++] = ch;
                if (buff_index == BUFFER_SIZE)
                {
                    print_buffer(char_buffer, &buff_index);
                    char_count += buff_index;
                }
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    char_buffer[buff_index++] = *str;
                    str++;
                    if (buff_index == BUFFER_SIZE)
                    {
                        print_buffer(char_buffer, &buff_index);
                        char_count += buff_index;
                    }
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int value = va_arg(args, int);
                printed_chars = print_positive_int(value);
                char_count += printed_chars;
            }
        }
        else
        {
            char_buffer[buff_index++] = *format;
            if (buff_index == BUFFER_SIZE)
            {
                print_buffer(char_buffer, &buff_index);
                char_count += buff_index;
            }
        }

        format++;
    }

    print_buffer(char_buffer, &buff_index);
    char_count += buff_index;

    va_end(args);

    return char_count;
}

int print_positive_int(int value)
{
    char num_buffer[32];
    int printed_chars = 0;

    if (value < 0)
    {
        putchar('-');
        printed_chars++;
        value = -value;
    }

    int index = 0;
    do
    {
        num_buffer[index++] = '0' + (value % 10);
        value /= 10;
        printed_chars++;
    } while (value > 0);

    for (int j = index - 1; j >= 0; j--)
    {
        putchar(num_buffer[j]);
    }

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        for (int i = 0; i < *buff_ind; i++)
        {
            putchar(buffer[i]);
        }
    }

    *buff_ind = 0;
}
