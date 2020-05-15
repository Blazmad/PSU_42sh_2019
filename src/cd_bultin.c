/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** change_directory.c
*/

#include "my.h"

char *make_str_home(char **env)
{
    char *home = NULL;
    int j = 0;
    int x = 0;

    for (int i = 0; env[i]; i++) {
        if (env[i][0] == 'H' && env[i][1] == 'O' &&
            env[i][2] == 'M' && env[i][3] == 'E') {
            home = malloc(sizeof(char) * my_strlen(env[i]) + 1);
            for (; env[i][j] != '/'; j++);
            for (; env[i][j]; j++, x++)
                home[x] = env[i][j];
            home[x] = '\0';
        }
    }
    return (home);
}

void update_env_element(stru_t *stru, int pwd_line, char *new_dir)
{
    int x = 0;
    char pwd[] = "PWD";

    for (; pwd[x]; x++)
        stru->envv[pwd_line][x] = pwd[x];
    stru->envv[pwd_line][x] = '\0';
    stru->envv[pwd_line] = my_strcat(stru->envv[pwd_line], "=");
    stru->envv[pwd_line] = my_strcat(stru->envv[pwd_line], new_dir);
}

int check_arg_cd(stru_t *stru)
{
    if (nb_tab_lines(stru->line) == 1 ||
        (stru->line[1][0] == '-' && stru->line[1][1] == '-' &&
        stru->line[1][2] == '\0'))
        return (0);
    return (1);
}

void cd_bultin_two(stru_t *stru)
{
    if (nb_tab_lines(stru->line) == 2 && stru->line[1][0] != '~') {
        stru->old_pwd = my_strdup(stru->pwd);
        if (chdir(stru->line[1]) == -1) {
            my_printf("%s: No such file or directory.\n", stru->line[1]);
            mysh(stru);
        } else {
            getcwd(stru->pwd, sizeof(stru->pwd));
            update_env_element(stru, search_pwd_element(stru), stru->pwd);
        }
    }
}

int cd_bultin(stru_t *stru)
{
    error_input_cd(stru);
    if (check_arg_cd(stru) == 0) {
        stru->old_pwd = my_strdup(stru->pwd);
        chdir(make_str_home(stru->envv));
        getcwd(stru->pwd, sizeof(stru->pwd));
        update_env_element(stru, search_pwd_element(stru), stru->pwd);
        return (0);
    } if (nb_tab_lines(stru->line) == 2 && stru->line[1][0] == '-' &&
        stru->line[1][1] == '\0') {
        if (stru->old_pwd != NULL) {
            chdir(stru->old_pwd);
            stru->old_pwd = my_strdup(stru->pwd);
            getcwd(stru->pwd, sizeof(stru->pwd));
            update_env_element(stru, search_pwd_element(stru), stru->pwd);
        }
        return (0);
    }
    cd_bultin_two(stru);
    return (0);
}