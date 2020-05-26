/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv_bultin.c
*/

#include "my.h"

char **add_arg_one(char **line, char **array, int i, int j)
{
    for (j = 0; j < my_strlen(line[1]); j++)
        array[i][j] = line[1][j];
    array[i][j] = '=';
    return (array);
}

char **add_arg_two(char **line, char **array, int i, int j)
{
    if (nb_tab_lines(line) == 3)
        for (int x = 0; x < my_strlen(line[2]); j++)
            array[i][j] = line[2][x++];
    array[i][j] = '\0';
    array[i + 1] = NULL;
    return (array);
}

char **add_env_element(char **line, stru_t *stru)
{
    char **array = malloc(sizeof(char *) * (count_env_lines(stru->envv) + 2));
    int len2 = 0;
    int i = 0;
    int j = 0;

    nb_tab_lines(line) == 3 ? len2 = my_strlen(line[2]) : 0;
    for (; i < nb_tab_lines(stru->envv); i++) {
        array[i] = malloc(sizeof(char) * my_strlen(stru->envv[i]) + 1);
        for (j = 0; stru->envv[i][j]; j++)
            array[i][j] = stru->envv[i][j];
        array[i][j] = '\0';
    }
    array[i] = malloc(sizeof(char) * (my_strlen(line[1]) + len2) + 2);
    array = add_arg_one(line, array, i, j);
    j = my_strlen(line[1]) + 1;
    array = add_arg_two(line, array, i, j);
    free_double_array(stru->envv);
    return (array);
}

void change_env_element(stru_t *stru, int line)
{
    int len1 = my_strlen(stru->line[1]);
    int len2 = 0;
    int x = 0;

    nb_tab_lines(stru->line) == 3 ? len2 = my_strlen(stru->line[2]) : 0;
    stru->envv[line] = malloc(sizeof(char) * (len1 + len2) + 2);
    for (int i = 0; stru->line[1][i]; i++, x++)
        stru->envv[line][x] = stru->line[1][i];
    stru->envv[line][x] = '=';
    x++;
    if (nb_tab_lines(stru->line) == 3)
        for (int j = 0; stru->line[2][j]; j++, x++)
            stru->envv[line][x] = stru->line[2][j];
    stru->envv[line][x] = '\0';
}

int setenv_bultin(stru_t *stru)
{
    int line = 0;

    error_input_setenv(stru);
    if (nb_tab_lines(stru->line) == 1) {
        put_env(stru);
        return (0);
    } if (nb_tab_lines(stru->line) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (0);
    } if ((line = search_env_element(stru, stru->line[1])) != -1)
        change_env_element(stru, line);
    else if (search_env_element(stru, stru->line[1]) == -1)
        stru->envv = add_env_element(stru->line, stru);
    return (0);
}