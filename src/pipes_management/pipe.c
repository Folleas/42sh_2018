/*
** EPITECH PROJECT, 2019
** MINISHELL2
** File description:
** pipe
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "structures.h"
#include "minishell.h"
#include "my_lib.h"
#include "enum.h"

static int initialize_pipe(data_t *shell)
{
    if (shell->pipe.status == START) {
        pipe(shell->pipe.pfd);
        init_pipe_first(shell);
        close(shell->pipe.pfd[1]);
        shell->pipe.prev_fd = shell->pipe.pfd[0];
    } else if (shell->pipe.status == MIDDLE) {
        pipe(shell->pipe.pfd);
        init_pipe_mid(shell);
        close(shell->pipe.pfd[1]);
        close(shell->pipe.prev_fd);
        shell->pipe.prev_fd = shell->pipe.pfd[0];
    } else {
        init_pipe_end(shell);
        close(shell->pipe.pfd[0]);
        close(shell->pipe.pfd[1]);
    }
    return (0);
}

static void set_commands_pipe(char *tmp, data_t *shell)
{
    free_array(shell->commands);
    shell->commands = my_str_to_word_array(tmp);
}

static void dispatch_pipe(data_t *shell, int nb_pipe, char **tmp)
{
    for (int i = 0; i < nb_pipe; i += 1) {
        if (i == 0) {
            set_commands_pipe(tmp[i], shell);
            shell->pipe.status = START;
            initialize_pipe(shell);
        } else if (i == (nb_pipe - 1)) {
            set_commands_pipe(tmp[i], shell);
            shell->pipe.status = END;
            initialize_pipe(shell);
        } else {
            set_commands_pipe(tmp[i], shell);
            shell->pipe.status = MIDDLE;
            initialize_pipe(shell);
        }
    }
    for (int i = 0; i < nb_pipe; i += 1)
        wait(NULL);
}

static int count_pipe_advanced(char **array)
{
    int i = 0;

    for (int j = 0; array[j] != NULL; j += 1) {
        if (array[j][0] != '\0')
            i += 1;
    }
    return (i);
}

int parsing_pipe(data_t *shell, char *cmd)
{
    int nb_pipe = count_pipe_advanced(shell->commands);
    char **tmp = my_tabcpy(shell->commands);

    if (tmp == NULL || tmp[0] == NULL)
        return (84);
    if (count_pipe(cmd) != (nb_pipe - 1)) {
        my_puterror("Invalid null command.\n");
        shell->ret_value = 1;
        return (0);
    }
    dispatch_pipe(shell, nb_pipe, tmp);
    free_array(tmp);
    return (0);
}