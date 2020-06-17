/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
#define MY_H_

#include "mysh.h"
#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdio.h>

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_strlen(char const *);
int my_putstr(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
char *my_strdup(char *src);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_show_word_array(char * const *);
int my_get_nb(char c);
void exam_flags_one(char *str, int i, va_list ap);
void exam_flag_characters(char *str, int i, va_list ap);
int my_put_uns_nbr(int nbr);
int my_get_nbr_base(int nb, char *base);
int my_get_nbr_base_printable(char const *str);
int my_get_nbr_base_pointer(int nb, char *base);
int my_printf(char *str, ...);

#endif