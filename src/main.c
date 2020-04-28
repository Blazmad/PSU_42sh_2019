/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    stru_t stru = init_stru(stru);

    if (ac != 1) {
        my_putstr("Usage: ./mysh\n");
        return (84);
    }
    stru = get_env(env, stru);
    mysh(stru);
    free_all(stru);
    return (0);
}