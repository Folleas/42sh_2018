/*
** EPITECH PROJECT, 2019
** MINISHELLTWO
** File description:
** pipe utils
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "structures.h"
#include "minishell.h"
#include "my_lib.h"
#include "enum.h"

int find_pipe(const char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == '|')
            j += 1;
    return (j);
}

int count_pipe(char const *str)
{
    int i = 0;

    for (int j = 0; str[j] != '\0'; j += 1)
        if (str[j] == '|')
            i += 1;
    return (i);
}

int init_pipe_first(data_t *shell)
{
    int pid;

    pid = fork();
    if (pid == 0) {
        close(shell->pipe.pfd[0]);
        dup2(shell->pipe.pfd[1], 1);
        close(shell->pipe.pfd[1]);
        parsing_commands(shell);
        exit(0);
    }
    return (0);
}
int init_pipe_mid(data_t *shell)
{
    int pid;

    pid = fork();
    if (pid == 0) {
        dup2(shell->pipe.prev_fd, 0);
        dup2(shell->pipe.pfd[1], 1);
        close(shell->pipe.pfd[1]);
        close(shell->pipe.prev_fd);
        parsing_commands(shell);
        exit(0);
    }
    return (0);
}
int init_pipe_end(data_t *shell)
{
    int pid;

    if (find_builtins_exec(shell) == 1)
        return (0);
    pid = fork();
    if (pid == 0) {
        close(shell->pipe.pfd[1]);
        dup2(shell->pipe.pfd[0], 0);
        close(shell->pipe.pfd[0]);
        parsing_commands(shell);
        exit(0);
    }
    return (0);
}