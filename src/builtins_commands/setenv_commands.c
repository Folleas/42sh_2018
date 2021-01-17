/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** setenv builtin management
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

static void initialize_value_setenv(char **env, char *values, int i)
{
    env[i] = re_alloc(env[i], my_strlen(env[i]), (my_strlen(env[i]) +
                                                    my_strlen(values)));
    env[i] = my_strcat(env[i], values);
    env[i + 1] = NULL;
}

static char **create_new_env(char **tmp_env, char **setenv_cmd)
{
    char **env = malloc(sizeof(char *) * (count_array(tmp_env) + 2));
    int i = 0;

    if (env == NULL)
        return (NULL);
    for (; i < count_array(tmp_env); i += 1)
        env[i] = my_strdup(tmp_env[i]);
    env[i] = my_strdup(setenv_cmd[0]);
    env[i] = re_alloc(env[i], my_strlen(env[i]), (my_strlen(env[i]) + 1));
    env[i] = my_strcat(env[i], "=");
    if (setenv_cmd[1] == NULL) {
        env[i + 1] = NULL;
        free_array(tmp_env);
        return (env);
    }
    initialize_value_setenv(env, setenv_cmd[1], i);
    free_array(tmp_env);
    return (env);
}

static int replace_old_value(char **env, char **setenv_cmd, int i)
{
    if (setenv_cmd[1] == NULL) {
        free(env[i]);
        env[i] = my_strdup(setenv_cmd[0]);
        env[i] = re_alloc(env[i], my_strlen(env[i]), (my_strlen(env[i]) + 1));
        env[i] = my_strcat(env[i], "=");
        return (0);
    } else {
        free(env[i]);
        env[i] = my_strdup(setenv_cmd[0]);
        env[i] = re_alloc(env[i], my_strlen(env[i]), (my_strlen(env[i]) + 1));
        env[i] = my_strcat(env[i], "=");
        env[i] = re_alloc(env[i], my_strlen(env[i]), (my_strlen(env[i]) +
                                                    my_strlen(setenv_cmd[1])));
        env[i] = my_strcat(env[i], setenv_cmd[1]);
    }
    return (0);
}

static int management_error_cd(data_t *shell)
{
    if (shell->commands[1] == NULL) {
        cmd_env(shell);
        return (1);
    }
    if (my_isalpha(shell->commands[1][0]) == 1) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        shell->ret_value = 1;
        return (1);
    }
    for (int i = 0; shell->commands[1][i] != '\0'; i += 1) {
        if (my_isalpha_num(shell->commands[1][i]) == 0) {
            my_puterror("setenv: Variable name must ");
            my_puterror("contain alphanumeric characters.\n");
            shell->ret_value = 1;
            return (1);
        }
    }
    return (0);
}

int cmd_setenv(data_t *shell)
{
    if (management_error_cd(shell) == 1)
        return (0);
    if (count_array(&shell->commands[1]) > 2) {
        my_puterror("setenv: Too many arguments.\n");
        shell->ret_value = 1;
        return (0);
    }
    for (int i = 0; shell->cpy_env[i] != NULL; i += 1)
        if (my_strncmp(shell->commands[1], shell->cpy_env[i],
            my_strlen(shell->commands[1])) == 0) {
            replace_old_value(shell->cpy_env, &shell->commands[1], i);
            return (0);
        }
    shell->cpy_env = create_new_env(shell->cpy_env, &shell->commands[1]);
    return (0);
}
