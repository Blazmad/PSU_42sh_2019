/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** change_env.c
*/

#include "my.h"

int search_env_element(stru_t stru, char *element)
{
    int j = 0;
    char *cmp = NULL;

    for (int i = 0; stru.envv[i]; i++) {
        cmp = malloc(sizeof(char) * my_strlen(stru.envv[i]) + 1);
        for (j = 0; stru.envv[i][j] != '='; j++)
            cmp[j] = stru.envv[i][j];
        cmp[j] = '\0';
        if (my_strcmp(cmp, element) == 0){
            free(cmp);
            return (i);
        }
    }
    free(cmp);
    return (-1);
}

int search_pwd_element(stru_t stru)
{
    int j = 0;
    char *cmp = NULL;

    for (int i = 0; stru.envv[i]; i++) {
        cmp = malloc(sizeof(char) * my_strlen(stru.envv[i]) + 1);
        for (j = 0; stru.envv[i][j] != '='; j++)
            cmp[j] = stru.envv[i][j];
        cmp[j] = '\0';
        if (my_strcmp(cmp, "PWD") == 0){
            free(cmp);
            return (i);
        }
    }
    free(cmp);
    return (0);
}

int count_env_lines(char **env)
{
    int i = 0;

    while (env[i])
        i++;
    return (i);
}