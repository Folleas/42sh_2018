/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** builtins management
*/

#include <stdlib.h>
#include "my_lib.h"
#include "minishell.h"

int find_builtins_exec(data_t *shell)
{
    builtin ptr[5] = {cmd_cd, cmd_setenv, cmd_unsetenv, cmd_env, cmd_exit};

    for (int i = 0; i < 5; i += 1) {
        if (my_strcmp(shell->commands[0], shell->builtins[i]) == 0) {
            ptr[i](shell);
            return (1);
        }
    }
    return (0);
}