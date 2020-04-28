/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** returns 1 if the string passed as parameter only contains uppercase, 0 if not
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int good = 0;

    while (str[i] != 0) {
        if (str[i] > 64 && str[i] < 91)
            good++;
        else
            return (0);
        i++;
    }
    if (good != 0)
        return (1);
    return (1);
}