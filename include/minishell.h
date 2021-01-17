/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** function prototype
*/

#ifndef MINISHELL_ONE_
#define MINISHELL_ONE_

#include "structures.h"

typedef int(*builtin)(data_t *shell);

/* minishell.c */
int minishell(char **env);
int free_array(char **array);
void free_all(data_t *shell);

/* environment.c */
char **copy_environment(char **env);

/* path.c */
char **copy_path_env(char **env);
char **copy_path(char **tmp_env, char **path);

/* prompt.c */
void display_prompt(void);

/* commands.c */
char **create_commands(char *tmp);
int parsing_commands(data_t *shell);
void exec_commands(data_t *shell, int i, char *tmp, int ret);
int commands_base(data_t *shell);

/* initialize_builtins.c */
char **initialize_builtins(void);

/* find_builtins.c */
int find_builtins_exec(data_t *shell);

/* env_commands.c */
int cmd_env(data_t *shell);

/* setenv__commands */
int cmd_setenv(data_t *shell);

/* unsetenv_commands */
int cmd_unsetenv(data_t *shell);

/* exit_commands.c */
int cmd_exit(data_t *shell);

/* cd_commands.c */
int cmd_cd(data_t *shell);

/* signal.c */
void check_signal(int sig);

/* commands_base.c */
char *concat_path(char *path, char *cmd);
void commands_ret(data_t *shell, int child);
void kill_child(data_t *shell, char *tmp, int ret);
int check_access(char *tmp, data_t *shell);

/* multiples_commands.c */
int count_commands(const char *str);
char **create_multi_commands(const char *str);

/* pipe.c */
int parsing_pipe(data_t *shell, char *cmd);

/* utils_pipe.c */
int find_pipe(const char *str);
int init_pipe_first(data_t *shell);
int init_pipe_mid(data_t *shell);
int init_pipe_end(data_t *shell);
int count_pipe(char const *str);

#endif
