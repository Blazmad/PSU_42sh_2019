/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if ((str[i] > 96 && str[i] < 123) && (i == 0 || str[i - 1] == ' '))
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}