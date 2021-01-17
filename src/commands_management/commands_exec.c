/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** management commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "my_lib.h"
#include "minishell.h"

char **create_commands(char *tmp)
{
    unsigned int len = 0;
    char **cpy_commands;

    if (tmp == NULL || tmp[0] == '\0')
        return (NULL);
    while (tmp[len] == ' ' || tmp[len] == '\t' || tmp[len] == ';')
        len += 1;
    cpy_commands = my_str_to_word_array(&tmp[len]);
    return (cpy_commands);
}

void exec_commands(data_t *shell, int i, char *tmp, int ret)
{
    execve(shell->commands[0], shell->commands, shell->cpy_env);
    if (errno == ENOEXEC) {
        my_puterror(shell->commands[0]);
        my_puterror(": Exec format error. Wrong Architecture.\n");
        kill_child(shell, tmp, 1);
    }
    for (; shell->path_array[i] != NULL; i += 1) {
        free(shell->commands[0]);
        shell->commands[0] = concat_path(shell->path_array[i], tmp);
        execve(shell->commands[0], shell->commands, shell->cpy_env);
    }
    if (check_access(tmp, shell) == 1)
        kill_child(shell, tmp, 1);
    if (shell->path_array[i] == NULL) {
        my_puterror(tmp);
        my_puterror(": Command not found.\n");
        ret = 1;
    }
    kill_child(shell, tmp, ret);
}

int commands_base(data_t *shell)
{
    int i = 0;
    char *tmp = my_strdup(shell->commands[0]);
    int child;
    int ret = 0;
    pid_t pid = fork();

    if (pid == 0)
        exec_commands(shell, i, tmp, ret);
    else
        waitpid(pid, &child, WUNTRACED | WCONTINUED);
    commands_ret(shell, child);
    free(tmp);
    return (0);
}

int parsing_commands(data_t *shell)
{
    if (shell->commands == NULL)
        return (0);
    if (find_builtins_exec(shell) == 1)
        return (0);
    commands_base(shell);
    return (0);
}
