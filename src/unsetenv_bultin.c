/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv_bultin.c
*/

#include "my.h"

char **remove_env_element(stru_t *stru, int line)
{
    char **array = malloc(sizeof(char *) * count_env_lines(stru->envv));
    int x = 0;

    if (line == -1)
        return (stru->envv);
    for (int i = 0, j = 0; i != count_env_lines(stru->envv); i++, x++, j++) {
        i == line ? i++ : 0;
        if (stru->envv[i] == NULL) {
            array[x] = NULL;
            free_double_array(stru->envv);
            return (array);
        }
        array[x] = malloc(sizeof(char) * (my_strlen(stru->envv[i]) + 1));
        for (j = 0; stru->envv[i][j]; j++)
            array[x][j] = stru->envv[i][j];
        array[x][j] = '\0';
    }
    array[x] = NULL;
    free_double_array(stru->envv);
    return (array);
}

void unsetenv_bultin(stru_t *stru)
{
    int line = 0;

    if (nb_tab_lines(stru->line) == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        mysh(stru);
    }
    for (int i = 1; stru->line[i]; i++) {
        line = search_env_element(stru, stru->line[i]);
        stru->envv = remove_env_element(stru, line);
    }
}