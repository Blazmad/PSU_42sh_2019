/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** exe_command.c
*/

#include "my.h"

void cat_env(stru_t *stru)
{
    for (int j = 0; stru->line[j] != NULL; j++) {
        my_putstr(stru->line[j]);
        my_putchar('\n');
    }
}

void strcat_to_path(stru_t *stru)
{
    if (stru->path == NULL)
        return;
    for (int i = 0; stru->path[i]; i++)
        stru->path[i] = my_strcat(my_strcat(stru->path[i], "/"),
            stru->line[stru->nb]);
}

char *get_command_into_path(stru_t *stru)
{
    strcat_to_path(stru);
    if (stru->path == NULL)
        return (NULL);
    if (access(stru->line[stru->nb], F_OK) == 0)
        return (stru->line[stru->nb]);
    for (int i = 0; stru->path[i] != NULL; i++) {
        if (access(stru->path[i], F_OK) == 0)
            return (stru->path[i]);
    }
    return (NULL);
}

void check_execve_error(stru_t *stru, char *command)
{
    DIR *dir = NULL;

    if (stru->line[stru->nb][0] == 0 || stru->line[stru->nb] == NULL)
        my_printf("%s: Exec format error, Wrong Architecture.\n",
            stru->line[stru->nb]);
    if (stru->line[stru->nb][0] == '/' ||
        (stru->line[stru->nb][0] == '.' && stru->line[stru->nb][1] == '/')) {
        if ((dir = opendir(stru->line[stru->nb])) != NULL ||
            (access(stru->line[stru->nb], R_OK | X_OK) == -1 &&
            execve(command, stru->line, stru->envv) == -1))
                my_printf("%s: Permission denied.\n", stru->line[stru->nb]);
    } else if (execve(command, stru->line, stru->envv) == -1)
        my_printf("%s: Command not found.\n", stru->line[stru->nb]);
}

// execve je dois lui envoyer que le ls et pas le ;

int execute_command(stru_t *stru)
{
    char *command = get_command_into_path(stru);
    int status = 0;
    pid_t pid;

    if (check_access_echo(stru, status, command) == 1) {
        redirection(stru);
        return (1);
    } if ((pid = fork()) == -1) {
        perror("fork_error\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        check_execve_error(stru, command);
        exit(0);
    } else
        waitpid(pid, &status, 0);
    error_segfault(status);
    return (0);
}