/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** reproduce the behavior of the str_str function
*/
#include <unistd.h>
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    if (to_find[0] == '\0' || to_find == NULL)
        return (str);
    if (str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        for (int j = 0, k = i; str[k] == to_find[j]
            && str[k] != '\0'; k++, j++) {
            if (to_find[j + 1] == '\0')
                return (&str[i]);
        }
        i++;
    }
    return (NULL);
}