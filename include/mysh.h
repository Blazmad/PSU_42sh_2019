/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all prototypes
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdarg.h>

#define quit __asm__("movq $60, %rax\nmovq $0, %rdi\nsyscall")
typedef struct stru
{
    char **path;
    char *str_path;
    char **line;
    char *str_line;
    char **envv;
    char pwd[100];
    char *old_pwd;
    int nb;
    char **tmp;
}stru_t;

//-cd_bultin.c
int cd_bultin(stru_t *stru);

//-error_input.c
void error_input_cd(stru_t *stru);
void error_input_exit(stru_t *stru);
int error_input_env(stru_t *stru);
void error_input_setenv(stru_t *stru);

//-exe_command.c
int execute_command(stru_t *stru);

//-free_all.c
void free_all(stru_t *stru);
void free_double_array(char **array);

//-get_env.c
void get_env(char **env, stru_t *stru);

//-get_line.c
void get_line(stru_t *stru);

//-get_path.c
void get_path(stru_t *stru);

//-mysh.c
stru_t init_stru(stru_t stru);
int mysh(stru_t *stru);
void init_and_exec(stru_t *stru);
int check_and_exec_command(stru_t *stru);

//-my_strlen_separator.c
int my_strlen_separator(char const *str);

//-redirection.c
int check_access_echo(stru_t *stru, int res, char *command);
void redirection(stru_t *stru);
int redirection_echo(stru_t *stru);

//search_element_env.c
int count_env_lines(char **env);
int search_env_element(stru_t *stru, char *element);
int search_pwd_element(stru_t *stru);

//-setenv_bultin.c
char **add_env_element(char **line, stru_t *stru);
int setenv_bultin(stru_t *stru);

//-signal.c
void error_segfault(int status);
void my_signal(void);

//-string_manip.c
char *clean_str(char *lineptr);
int compar(char *get, char *str, int size);
int nb_tab_lines(char **tab);
void put_env(stru_t *stru);
char *move_spaces(char *lineptr);

//-to_array_command.c
char **make_double_array_tmp(char *str);
void clean_to_array(stru_t *stru);
int count_line(char *str);

//-unsetenv_bultin.c
int unsetenv_bultin(stru_t *stru);

//-utils.c
int check_first_is_letter(char *str);
int check_is_alphanumeric(char *str);
int is_directory(char *str);
int is_file(char *str);
char *remove_wave_str(char *str);