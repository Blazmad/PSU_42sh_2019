/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        if (i == n)
            dest[i] = '\0';
        i++;
    }
    return (dest);
}