/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** returns 1 if the string contains alphabetical characters and 0 if not
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int good = 0;

    while (str[i] != 0) {
        if (str[i] > 65 && str[i] < 90)
            good++;
        else if (str[i] > 97 && str[i] < 122)
            good++;
        else
            return (0);
        i++;
    }
    if (good != 0)
        return (1);
    return (1);
}