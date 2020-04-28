/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** returns 1 if the string contains numbers and 0 if not
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int good = 0;

    while (str[i] != 0) {
        if (str[i] > 47 && str[i] < 58)
            good++;
        else
            return (0);
        i++;
    }
    if (good != 0)
        return (1);
    return (1);
}