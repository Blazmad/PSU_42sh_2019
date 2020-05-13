/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_env.c
*/

#include "my.h"

void get_env(char **env, stru_t *stru)
{
    stru->envv = malloc(sizeof(char *) * (count_env_lines(env) + 1));
    int i = 0;
    int j = 0;

    while (i < count_env_lines(env)) {
        stru->envv[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        j = 0;
        while (env[i][j]) {
            stru->envv[i][j] = env[i][j];
            j++;
        }
        stru->envv[i][j] = '\0';
        i++;
    }
    stru->envv[i] = NULL;
}