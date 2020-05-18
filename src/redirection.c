/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** redirection.c
*/

#include "my.h"

void redirection_echo(stru_t *stru)
{
    int fd = 0;
    char *str = NULL;

    for (int i = 0; stru->line[i]; i++) {
        if (my_strcmp(stru->line[i], ">") == 0) {
            str = stru->line[i - 1];
            i++;
            fd = open(stru->line[i], O_CREAT | O_WRONLY | O_TRUNC,
            S_IRWXU);
            write(fd, str, my_strlen(str));
            write(fd, "\n", 2);
        }
    }
}

void redirection(stru_t *stru)
{
    for (int i = 0; stru->line[i]; i++) {
        if (my_strcmp(stru->line[i], ">") == 0) {
            i++;
            open(stru->line[i], O_CREAT | O_WRONLY | O_TRUNC,
            S_IRWXU);
        }
    }
}

int check_access_echo(stru_t *stru, int res, char *command)
{
    if (command == NULL)
        return (1);
    if (my_strcmp(stru->line[0], "echo") == 0) {
        redirection_echo(stru);
        error_segfault(res);
        mysh(stru);
    }
    return (0);
}