/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** free_all.c
*/

#include "my.h"

void free_double_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void free_all(stru_t *stru)
{
    free_double_array(stru->envv);
    if (stru->str_line != NULL)  {
        free(stru->str_line);
        free_double_array(stru->line);
    } if (stru->str_path != NULL) {
        free(stru->str_path);
        free_double_array(stru->path);
    }
    stru->nb = 0;
}