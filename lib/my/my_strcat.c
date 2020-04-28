/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);

    if (dest != NULL) {
        while (dest[i] != 0) {
            res[i] = dest[i];
            i++;
        }
    }
    while (src[j] != 0) {
        res[i] = src[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}