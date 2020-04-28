/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_uns_nbr.c
*/

#include "my.h"

int my_put_uns_nbr(int nbr)
{
    unsigned nb_uns = nbr;
    int nbr2;

    if (nb_uns >= 10) {
        nbr2 = nb_uns % 10;
        nb_uns = nb_uns / 10;
        my_put_uns_nbr(nb_uns);
        my_putchar(nbr2 + 48);
    } else
        my_putchar((nb_uns % 10) + 48);
    return (0);
}