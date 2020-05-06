/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** signal.c
*/

#include "my.h"

void ctrl_c(int sign)
{
    char str[100];

    (void)sign;
    my_printf("\n\033[33m42sh$>\033[36m[%s] \033[33m~ \033[0m",
        getcwd(str, sizeof(str)));
}

void my_signal(void)
{
    if (signal(SIGINT, ctrl_c) == SIG_ERR)
        perror("error: problem wit signal SIGInt.\n");
}