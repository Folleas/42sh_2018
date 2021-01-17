/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** commands cd management
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

static char *back_home(char **env)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "HOME=", 5) == 0)
            return (&env[i][5]);
    }
    return ("\0");
}

static void error_gestion(data_t *shell, int ret)
{
    if (ret == -1) {
        my_puterror(shell->commands[1]);
        my_puterror(": ");
        my_puterror(strerror(errno));
        my_puterror(".\n");
        shell->ret_value = 1;
    }
}

int cmd_cd(data_t *shell)
{
    int ret = 0;
    static char path[FILENAME_MAX];
    static char path_old[FILENAME_MAX];
    char *tmp;

    if (shell->commands[1] == NULL || my_strcmp(shell->commands[1], "~") == 0) {
        getcwd(path_old, FILENAME_MAX);
        ret = chdir(back_home(shell->cpy_env));
        getcwd(path, FILENAME_MAX);
    } else if (my_strcmp(shell->commands[1], "-") == 0) {
        tmp = my_strdup(path_old);
        getcwd(path_old, FILENAME_MAX);
        chdir(tmp);
        getcwd(path, FILENAME_MAX);
    } else {
        getcwd(path_old, FILENAME_MAX);
        ret = chdir(shell->commands[1]);
        getcwd(path, FILENAME_MAX);
    }
    error_gestion(shell, ret);
    return (0);
}
