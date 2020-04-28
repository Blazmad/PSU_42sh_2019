/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocates memory and copies the string given as argument in it
*/
#include "my.h"

char *my_strdup(char *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * len + 1);

    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}