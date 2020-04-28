/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** displays N if the integer is negative, P, if positive or nul
*/

int my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    if (n >= 0)
        my_putchar('P');
    return (n);
}