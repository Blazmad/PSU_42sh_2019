/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** utils.c
*/

#include "my.h"

int is_directory(char *str)
{
    struct stat file;

    file.st_mode = 0;
    stat(str, &file);
    if (S_ISDIR(file.st_mode))
        return (0);
    return (1);
}

int is_file(char *str)
{
    struct stat file;

    file.st_mode = 0;
    stat(str, &file);
    if (S_ISREG(file.st_mode))
        return (0);
    return (1);
}

char *remove_wave_str(char *str)
{
    int x = 0;
    char *cpy = malloc(sizeof(char) * my_strlen(str));

    for (int i = 1; str[i]; i++) {
        cpy[x] = str[i];
        x++;
    }
    cpy[x] = '\0';
    free(str);
    return (cpy);
}

int check_first_is_letter(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
        return (0);
    if (str[0] >= 'A' && str[0] <= 'Z')
        return (0);
    return (1);
}

int check_is_alphanumeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0')
            return (1);
        if (str[i] > '9' && str[i] < 'A')
            return (1);
        if (str[i] > 'Z' && str[i] < 'a')
            return (1);
        if (str[i] > 'z')
            return (1);
    }
    return (0);
}