/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_convert_nbr_base.c
*/

#include "my.h"

int my_get_nbr_base(int nb, char *base)
{
    if (nb == 0)
        return (0);
    else {
        my_get_nbr_base(nb / my_strlen(base), base);
        my_putchar(base[nb % my_strlen(base)]);
    }
    return (0);
}

int my_get_nbr_base_pointer(int nb, char *base)
{
    my_putstr("0x");
    if (nb == 0)
        return (0);
    else {
        my_get_nbr_base(nb / my_strlen(base), base);
        my_putchar(base[nb % my_strlen(base)]);
    }
    return (0);
}

void octal(int nbr)
{
    char *base = "01234567";

    my_get_nbr_base(nbr / my_strlen(base), base);
    my_putchar(base[nbr % my_strlen(base)]);
}

int my_get_nbr_base_printable(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] <= 31) {
            my_putchar('\\');
            if (str[i] < 32)
                my_putchar('0');
            if (str[i] < 8)
                my_putstr("0");
            octal(str[i]);
        } else
            my_putchar(str[i]);
        i++;
    }
    return (0);
}