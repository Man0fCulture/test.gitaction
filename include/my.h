/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-suleman.maqsood
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #define ERROR 84
    typedef struct env_s {
        char **bin;
        int nbw;
        char *old_pwd;
        char **fon;
        char **env;
        int nbl_denv;
        int error;
    }env_t;

char **my_str_to_word_array(char *str);
int my_strlen(char *str);
int my_execute(char **env, char *line, env_t *en);
char **stock_mypath(char **env, env_t *en);
int create_cd(char *fon, char **env, env_t *en);
int my_putstr(char const *str);
int check_fonction(char *line, char **env, env_t *en);
char **stock_env(char **env, env_t *en);
int print_env(env_t *en);
int set_env(env_t *en);
void free_fon(env_t *en);
int create_new_env(env_t *en);
int free_ele_env(env_t *en);
int un_set_env(env_t *en);
int delete_ele_env(int l, env_t *en);
int cd_to_home(env_t *en);
int find_pwd(char **env);
int find_home(char **env);
int cd_minus(env_t *en);
int find_old_pwd(char **env);
int put_old_pwd(env_t *en);
int set_env_void(env_t *en);
int create_new_env_void(env_t *en);
int create_new_env_for_cd(env_t *en);

#endif
