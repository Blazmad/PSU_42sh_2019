/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** displays the content of an array of words
*/
#include <stdlib.h>

int my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char **src)
{
    int i = 0;

    while (src[i] != 0) {
        my_putstr(src[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}