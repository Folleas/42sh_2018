/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** commands base
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

char *concat_path(char *path, char *cmd)
{
    char *tmp = my_strdup(path);

    tmp = re_alloc(tmp, my_strlen(tmp), (my_strlen(tmp) + 1));
    tmp = my_strcat(tmp, "/");
    tmp = re_alloc(tmp, my_strlen(tmp), (my_strlen(tmp) + my_strlen(cmd)));
    tmp = my_strcat(tmp, cmd);
    return (tmp);
}

static void check_child(int child)
{
    if (WTERMSIG(child) == 6)
        my_puterror("Abort");
    if (WTERMSIG(child) == 11)
        my_puterror("Segmentation fault");
    if (WTERMSIG(child) == 8)
        my_puterror("Floating exception");
}

void commands_ret(data_t *shell, int child)
{
    if (WIFSIGNALED(child)) {
        check_child(child);
        if (WCOREDUMP(child))
            my_puterror(" (core dump)");
        my_puterror("\n");
        shell->ret_value = WTERMSIG(child) + 128;
    }
    else if (WIFEXITED(child))
        shell->ret_value = WEXITSTATUS(child);
}

void kill_child(data_t *shell, char *tmp, int ret)
{
    free(tmp);
    free_all(shell);
    exit(ret);
}

int check_access(char *tmp, data_t *shell)
{
    if (access(tmp, R_OK) == 0) {
        my_puterror(tmp);
        my_puterror(": Permission denied.\n");
        shell->ret_value = 1;
        return (1);
    }
    return (0);
}
