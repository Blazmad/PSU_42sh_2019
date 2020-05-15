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
            stru->line[0]);
}

char *get_command_into_path(stru_t *stru)
{
    strcat_to_path(stru);
    if (stru->path == NULL)
        return (NULL);
    if (access(stru->line[0], F_OK) == 0)
        return (stru->line[0]);
    for (int i = 0; stru->path[i] != NULL; i++) {
        if (access(stru->path[i], F_OK) == 0)
            return (stru->path[i]);
    }
    return (NULL);
}

void check_execve_error(stru_t *stru, char *command)
{
    DIR *dir = NULL;

    if (stru->line[0][0] == 0 || stru->line[0] == NULL)
        my_printf("%s: Exec format error, Wrong Architecture.\n",
            stru->line[0]);
    if (stru->line[0][0] == '/' ||
        (stru->line[0][0] == '.' && stru->line[0][1] == '/')) {
        if ((dir = opendir(stru->line[0])) != NULL ||
            (access(stru->line[0], R_OK | X_OK) == -1 &&
            execve(command, stru->line, stru->envv) == -1))
                my_printf("%s: Permission denied.\n", stru->line[0]);
    } else if (execve(command, stru->line, stru->envv) == -1)
        my_printf("%s: Command not found.\n", stru->line[0]);
}

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