/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** unsetenv
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

static char **remove_var_env(char **tmp_env, char const *str)
{
    char **env = malloc(sizeof(char *) * (count_array(tmp_env) + 1));
    int count = 0;

    if (env == NULL)
        return (NULL);
    for (int i = 0; tmp_env[i] != NULL; i += 1) {
        if (my_strncmp(tmp_env[i], str, my_strlen(str)) == 0)
            i += 1;
        if (tmp_env[i] == NULL)
            break;
        env[count] = my_strdup(tmp_env[i]);
        count += 1;
    }
    env[count] = NULL;
    free_array(tmp_env);
    return (env);
}

int cmd_unsetenv(data_t *shell)
{
    if (shell->commands[1] == NULL) {
        my_puterror("unsetenv: Too few arguments.\n");
        shell->ret_value = 1;
        return (0);
    }
    for (int i = 1; shell->commands[i] != NULL; i += 1)
        shell->cpy_env = remove_var_env(shell->cpy_env, shell->commands[i]);
    return (0);
}
