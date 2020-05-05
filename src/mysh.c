/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** mysh.c
*/

#include "my.h"

int check_bultin_command(stru_t stru)
{
    if (compar(stru.line[0], "exit", 4))
        error_input_exit(stru);
    if (compar(stru.line[0], "env", 3))
        error_input_env(stru);
    if (compar(stru.line[0], "cd", 2)) {
        stru = cd_bultin(stru);
        mysh(stru);
    }
    if (compar(stru.line[0], "setenv", 6)) {
        stru = setenv_bultin(stru);
        mysh(stru);
    }
    if (compar(stru.line[0], "unsetenv", 8)) {
        stru = unsetenv_bultin(stru);
        mysh(stru);
    }
    return (0);
}

int mysh(stru_t stru)
{
    while (1) {
        my_signal();
        my_printf("\033[33m42sh$>\033[36m[%s] \033[33m~ \033[0m", stru.pwd);
        stru = get_line(stru);
        stru = get_path(stru);
        if (stru.str_line[0] == '\n')
            mysh(stru);
        check_bultin_command(stru);
        if (execute_command(stru) == 0)
            mysh(stru);
        else
            my_printf("%s: Command not found.\n", stru.line[0]);
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
    getcwd(stru.pwd, sizeof(stru.pwd));
    return (stru);
}