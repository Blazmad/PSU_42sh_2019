/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mysh.c
*/

#include "my.h"

int check_bultin_command(stru_t *stru)
{
    if (compar(stru->line[stru->nb], "exit", 4))
        error_input_exit(stru);
    if (compar(stru->line[stru->nb], "env", 3))
        error_input_env(stru);
    if (compar(stru->line[stru->nb], "cd", 2)) {
        cd_bultin(stru);
        mysh(stru);
    } if (compar(stru->line[stru->nb], "setenv", 6)) {
        setenv_bultin(stru);
        mysh(stru);
    } if (compar(stru->line[stru->nb], "unsetenv", 8)) {
        unsetenv_bultin(stru);
        mysh(stru);
    }
    return (0);
}

int check_and_exec_command(stru_t *stru)
{
    if (stru->str_line[stru->nb] == '\n')
        mysh(stru);
    check_bultin_command(stru);
    if (execute_command(stru) == 0)
        mysh(stru);
    else
        my_printf("%s: Command not found.\n", stru->line[stru->nb]);
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
    getcwd(stru.pwd, sizeof(stru.pwd));
    return (stru);
}