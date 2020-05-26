/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_env.c
*/

#include "my.h"

char **put_brut_path(void)
{
    char **line = malloc(sizeof(char *) * 4);
    line[0] = "setenv";
    line[1] = "PATH";
    line[2] = "/home/cmadzar/.local/bin:/home/cmadzar/bin:/usr/local/bin:/usr";
    line[2] = my_strcat(line[2], "/local/sbin:/usr/bin:/usr/sbin:/home/cmadz");
    line[2] = my_strcat(line[2], "ar/.composer/vendor/bin:/var/lib/snapd/sna");
    line[2] = my_strcat(line[2], "p/bin:/home/cmadzar/my_scripts/:/home/cmadz");
    line[2] = my_strcat(line[2], "ar/my_scripts/:/home/cmadzar/my_scripts/");
    line[3] = NULL;

    return (line);
}

void get_env(char **env, stru_t *stru)
{
    stru->envv = malloc(sizeof(char *) * (count_env_lines(env) + 1));
    int i = 0;
    int j = 0;
    char **line = put_brut_path();

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
    if (search_env_element(stru, "PATH") == -1)
        stru->envv = add_env_element(line, stru);
}