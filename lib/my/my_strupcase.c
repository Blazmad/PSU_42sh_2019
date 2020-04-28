/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** puts every letter of every word in it in upercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}