/*
** EPITECH PROJECT, 2019
** my_is_prime_sup
** File description:
** return the smallest prime number that is greater than the number's parameter
*/

int my_find_prime_sup(int nb)
{
    int i = 2;

    if (nb < 2)
        return (2);
    if (nb == 2)
        return (3);
    while (i < nb) {
        if (nb % i == 0)
            nb++;
        i++;
    }
    return (nb);
}