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
}stru_t;

//-cd_bultin.c
stru_t cd_bultin(stru_t stru);

//-error_input.c
void error_input_cd(stru_t stru);
void error_input_exit(stru_t stru);
void error_input_env(stru_t stru);
void error_input_setenv(stru_t stru);

//-exe_command.c
int execute_command(stru_t stru);

//-free_all.c
void free_all(stru_t stru);
void free_double_array(char **array);

//-get_env.c
stru_t get_env(char **env, stru_t stru);

//-get_line.c
stru_t get_line(stru_t stru);

//-get_path.c
stru_t get_path(stru_t stru);

//-mysh.c
stru_t init_stru(stru_t stru);
int mysh(stru_t stru);

//search_element_env.c
int count_env_lines(char **env);
int search_env_element(stru_t stru, char *element);
int search_pwd_element(stru_t stru);

//-setenv_bultin.c
stru_t setenv_bultin(stru_t stru);

//-signal.c
void error_segfault(int status);
void my_signal(void);

//-string_manip.c
char *clean_str(char *lineptr);
int compar(char *get, char *str, int size);
int nb_tab_lines(char **tab);
void put_env(stru_t stru);

//-unsetenv_bultin.c
stru_t unsetenv_bultin(stru_t stru);

//-utils.c
int check_first_is_letter(char *str);
int check_is_alphanumeric(char *str);
int is_directory(char *str);
int is_file(char *str);
char *remove_wave_str(char *str);