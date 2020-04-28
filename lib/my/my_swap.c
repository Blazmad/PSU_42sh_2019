/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swaps the content of two integers
*/

char my_putchar(char c);

void my_swap(int *a, int *b)
{
    int cpy = 0;

    cpy = *a;
    *a = *b;
    *b = cpy;
}