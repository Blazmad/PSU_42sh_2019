/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mysh.c
*/

#include "my.h"

int check_bultin_command(stru_t *stru)
{
    if (compar(stru->line[0], "exit", 4)) {
        error_input_exit(stru);
        return (0);
    } if (compar(stru->line[0], "env", 3)) {
        if (error_input_env(stru) == 0)
            return (0);
    } if (compar(stru->line[0], "cd", 2)) {
        if (cd_bultin(stru) == 0)
            return (0);
    } if (compar(stru->line[0], "setenv", 6)) {
        if (setenv_bultin(stru) == 0)
            return (0);
    } if (compar(stru->line[0], "unsetenv", 8)) {
        if (unsetenv_bultin(stru) == 0)
            return (0);
    }
    return (1);
}

int check_and_exec_command(stru_t *stru)
{
    if (stru->str_line[0] == '\n') {
        mysh(stru);
    } if (check_bultin_command(stru) == 0) {
        stru->nb++;
        init_and_exec(stru);
    } if (execute_command(stru) == 0) {
        stru->nb++;
        init_and_exec(stru);
    } else {
        my_printf("%s: Command not found.\n", stru->line[0]);
        stru->nb++;
        init_and_exec(stru);
    }
    return (0);
}

void init_and_exec(stru_t *stru)
{
    get_line(stru);
    get_path(stru);
    check_and_exec_command(stru);
}

int mysh(stru_t *stru)
{
    while (1) {
        my_signal();
        my_printf("\033[33m42sh$>\033[36m[%s] \033[33m~ \033[0m", stru->pwd);
        init_and_exec(stru);
    }
    return (0);
}

stru_t init_stru(stru_t stru)
{
    stru.str_line = NULL;
    stru.line = NULL;
    stru.str_path = NULL;
    stru.path = NULL;
    stru.old_pwd = NULL;
    stru.nb = 0;
    stru.tmp = NULL;
    getcwd(stru.pwd, sizeof(stru.pwd));
    return (stru);
}