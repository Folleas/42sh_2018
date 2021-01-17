/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** minishell management
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

void free_all(data_t *shell)
{
    free_array(shell->cpy_env);
    free_array(shell->path_array);
}

static data_t initialize_struct(char **env)
{
    data_t shell;

    shell.cpy_env = my_tabcpy(env);
    shell.path_array = copy_path_env(shell.cpy_env);
    shell.builtins = initialize_builtins();
    shell.ret_exit = -84;
    shell.ret_value = 0;
    shell.pipe.status = -1;
    return (shell);
}

int free_array(char **array)
{
    if (array == NULL)
        return (0);
    for (int i = 0; array[i] != NULL; i += 1)
        free(array[i]);
    free(array);
    return (0);
}

static int management_commands(data_t *shell, char *tmp)
{
    char **array;

    array = create_multi_commands(tmp);
    if (array == NULL || array[0] == NULL)
        return (0);
    for (int j = 0; array[j] != NULL; j += 1) {
        if (find_pipe(array[j]) != 0) {
            shell->commands = my_str_to_word_pimp(array[j], '|');
            parsing_pipe(shell, array[j]);
        } else {
            shell->commands = create_commands(array[j]);
            parsing_commands(shell);
        }
        free_array(shell->commands);
        shell->path_array = copy_path(shell->cpy_env, shell->path_array);
    }
    free_array(array);
    return (0);
}

int minishell(char **env)
{
    data_t shell = initialize_struct(env);
    char *tmp = malloc(sizeof(char));

    signal(SIGINT, check_signal);
    display_prompt();
    while (tmp != NULL) {
        free(tmp);
        tmp = get_next_line(0);
        management_commands(&shell, tmp);
        if (shell.ret_exit != -84) {
            free_all(&shell);
            free(tmp);
            return (shell.ret_exit);
        }
        if (isatty(0) == 1)
            display_prompt();
    }
    free_all(&shell);
    return (shell.ret_value);
}
