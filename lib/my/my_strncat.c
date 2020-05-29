/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates n characters of the src string to the end of the dest string
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int d = my_strlen(dest);

    while (src[i] != 0 && i < nb) {
        dest[d + i] = src[i];
        i++;
    }
    dest[d + i] = '\0';
    return (dest);
}