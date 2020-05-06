/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_path.c
*/

#include "my.h"

int count_path_lines(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] == ':')
            count++;
        i++;
    }
    return (count + 1);
}

int count_path_char(char *str, int i)
{
    int count = 0;

    while (str[i]) {
        if (str[i] == ':' || str[i] == '\0')
            return (count);
        count++;
        i++;
    }
    return (count);
}

char **make_double_array_path(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (count_path_lines(str) + 1));

    for (; str[k] != '/' && str[k] != '\0'; k++);
    while (i < count_path_lines(str)) {
        array[i] = malloc(sizeof(char) * count_path_char(str, k) + 1);
        j = 0;
        while (str[k] != ':' && str[k] != '\0') {
            array[i][j] = str[k];
            j++;
            k++;
        }
        array[i][j] = '\0';
        i++;
        k++;
    }
    array[i] = NULL;
    return (array);
}

char *make_str_path(char **env)
{
    char *path = NULL;
    int j = 0;

    for (int i = 0; env[i]; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A') {
            path = malloc(sizeof(char) * my_strlen(env[i]) + 1);
            for (; env[i][j]; j++)
                path[j] = env[i][j];
            path[j] = '\0';
        }
    }
    return (path);
}

stru_t get_path(stru_t stru)
{
    if (stru.str_path != NULL) {
        free(stru.str_path);
        free_double_array(stru.path);
    }
    stru.str_path = make_str_path(stru.envv);
    stru.path = make_double_array_path(stru.str_path);
    return (stru);
}