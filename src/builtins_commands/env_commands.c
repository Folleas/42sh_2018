/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** env commands
*/

#include <stdlib.h>
#include "my_lib.h"
#include "minishell.h"

int cmd_env(data_t *shell)
{
    if (count_array(shell->commands) > 1) {
        my_puterror("env: '");
        my_puterror(shell->commands[1]);
        my_puterror("': No such file or directory\n");
        shell->ret_value = 127;
        return (0);
    }
    for (int i = 0; shell->cpy_env[i] != NULL; i += 1) {
        my_putstr(shell->cpy_env[i]);
        my_putchar('\n');
    }
    return (0);
}
