/*
** EPITECH PROJECT, 2019
** CPool_my_printf_2019
** File description:
** my_printf.c
*/

#include "my.h"

void exam_flag_characters(char *str, int i, va_list ap)
{
    switch (str[i]) {
    case ' ':
    case '#':
        i++;
        exam_flags_one(str, i, ap);
        break;
    case '0':
        i++;
        exam_flags_one(str, i, ap);
        break;
    case '-':
        i++;
        exam_flags_one(str, i, ap);
        break;
    case '+':
        i++;
        exam_flags_one(str, i, ap);
        break;
    }
}

void exam_flags_three(char *str, int i, va_list ap)
{
    switch (str[i]) {
    case 'p':
        my_get_nbr_base_pointer(va_arg(ap, int), "0123456789abcdef");
        break;
    }
    exam_flag_characters(str, i, ap);
}

void exam_flags_two(char *str, int i, va_list ap)
{
    switch (str[i]) {
    case 'S':
        my_get_nbr_base_printable(va_arg(ap, char *));
        break;
    case 'b':
        my_get_nbr_base(va_arg(ap, int), "01");
        break;
    case 'o':
        my_get_nbr_base(va_arg(ap, int), "01234567");
        break;
    case 'x':
        my_get_nbr_base(va_arg(ap, int), "0123456789abcdef");
        break;
    case 'X':
        my_get_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
        break;
    }
    exam_flags_three(str, i, ap);
}

void exam_flags_one(char *str, int i, va_list ap)
{
    switch (str[i]) {
    case '%':
        my_putchar('%');
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'u':
        my_put_uns_nbr(va_arg(ap, int));
        break;
    case 'c':
        my_putchar(va_arg(ap, int));
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    }
    exam_flags_two(str, i, ap);
}

int my_printf(char *str, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            exam_flags_one(str, i, ap);
        } else
            my_putchar(str[i]);
        i++;
    }
    va_end(ap);
    return (0);
}