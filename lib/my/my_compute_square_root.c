/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** returns the square root of the number given as argument
*/

int my_compute_square_root(int nb)
{
    int res = 0;

    if (nb < 0)
        return (0);
    while (res * res < nb)
        res++;
    if (res * res == nb)
        return (res);
    else
        return (0);
    return (res);
}