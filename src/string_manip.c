/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** string_manip.c
*/

#include "my.h"

char *move_spaces(char *lineptr)
{
    char *cpy = malloc(sizeof(char) * my_strlen(lineptr) + 1);
    int k = 0;
    int a = 0;

    for (int x = 0; lineptr[x]; x++) {
        if (lineptr[x] != ' ' && lineptr[x] != '\t') {
            cpy[k++] = lineptr[x];
            a = 1;
        }
        if (lineptr[x] == ' ' && (lineptr[x + 1] != ' ' &&
            lineptr[x + 1] != '\t' && lineptr[x + 1] != '\0') && a == 1)
            cpy[k++] = lineptr[x];
        else if (lineptr[x] == '\t' && (lineptr[x + 1] != ' ' &&
            lineptr[x + 1] != '\t' && lineptr[x + 1] != '\0') && a == 1)
            cpy[k++] = ' ';
    }
    cpy[k] = '\0';
    return (cpy);
}

char *clean_str(char *lineptr)
{
    char *dest = malloc(sizeof(char) * my_strlen(lineptr) + 1);
    int i = 0;

    if (lineptr[i] == '\n')
        return ("\n");
    lineptr = move_spaces(lineptr);
    if (lineptr[i] == '\n')
        return ("\n");
    while (lineptr[i] != '\0') {
        if (lineptr[i] != '\n')
            dest[i] = lineptr[i];
        i++;
    }
    dest[i - 1] = '\0';
    return (dest);
}

int compar(char *get, char *str, int size)
{
    int i = 0;

    if (my_strlen(get) != my_strlen(str))
        return (0);
    while (i < size) {
        if (get[i] != str[i])
            return (0);
        i++;
    }
    return (1);
}

void put_env(stru_t *stru)
{
    int i = 0;

    while (stru->envv[i] != NULL) {
        my_putstr(stru->envv[i]);
        my_putchar('\n');
        i++;
    }
}

int nb_tab_lines(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return (i);
}