/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** that returns 1 if the string passed as parameter only contains, 0 if not
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int good = 0;

    while (str[i] != 0) {
        if (str[i] > 31 && str[i] < 127)
            good++;
        else
            return (0);
        i++;
    }
    if (good != 0)
        return (1);
    return (1);
}