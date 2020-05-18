/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** error_input.c
*/

#include "my.h"

void error_input_exit(stru_t *stru)
{
    if (nb_tab_lines(stru->line) == 1) {
        my_putstr("exit\n");
        free_all(stru);
        exit(0);
    }
    my_putstr("exit: Expression Syntax.\n");
}

int error_input_env(stru_t *stru)
{
    if (nb_tab_lines(stru->line) == 1) {
        put_env(stru);
        return (0);
    }
    if (is_directory(stru->line[1]) == 0)
        my_printf("env: ‘%s’: Permission denied\n", stru->line[1]);
    else
        my_printf("env: ‘%s’: No such file or directory\n", stru->line[1]);
    return (0);
}

void error_input_cd(stru_t *stru)
{
    if (nb_tab_lines(stru->line) > 2) {
        my_putstr("cd: Too many arguments.\n");
        mysh(stru);
    }
    if (nb_tab_lines(stru->line) == 2) {
        if (stru->line[1][0] == '~' && stru->line[1][1] != '\0' &&
            stru->line[1][1] != '/') {
            my_printf("Unknown user: %c.\n", stru->line[1][1]);
            mysh(stru);
        }
        if (is_file(stru->line[1]) == 0) {
            my_printf("%s: Not a directory.\n", stru->line[1]);
            mysh(stru);
        }
        else if (is_directory(stru->line[1]) != 0 && (stru->line[1][0] != '~' &&
            stru->line[1][0] != '-')) {
            my_printf("%s: No such file or directory.\n", stru->line[1]);
            mysh(stru);
        }
    }
}

void error_input_setenv(stru_t *stru)
{
    if (nb_tab_lines(stru->line) == 2 || nb_tab_lines(stru->line) == 3) {
        if (check_first_is_letter(stru->line[1]) == 1) {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            mysh(stru);
        } else if (check_is_alphanumeric(stru->line[1]) == 1) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            mysh(stru);
        }
    }
}

void error_segfault(int status)
{
    if (status == 8) {
        my_putstr("Floating exception\n");
        return;
    }
    if (status == 139) {
        my_putstr("Segmentation fault (core dump)\n");
        return;
    }
    if (status == 136) {
        my_putstr("Floating exception (core dump)\n");
        return;
    }
    if (status == 11) {
        my_putstr("Segmentation fault\n");
        return;
    }
}