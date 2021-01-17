/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** exit commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

static int check_charac(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
            i += 1;
        else
            return (-1);
    }
    return (0);
}

static int check_sign(char const *str)
{
    int count_sign = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '-')
            count_sign += 1;
    }
    if (count_sign > 1)
        return (-1);
    return (0);
}

int cmd_exit(data_t *shell)
{
    if (shell->commands[1] == NULL) {
        shell->ret_exit = 0;
        return (0);
    }
    if (check_sign(shell->commands[1]) == -1) {
        my_puterror("exit: Badly formed number.\n");
        shell->ret_value = 1;
        return (0);
    }
    if (check_charac(shell->commands[1]) == -1) {
        my_puterror("exit: Expression Syntax.\n");
        shell->ret_value = 1;
        return (0);
    }
    shell->ret_exit = my_getnbr(shell->commands[1]);
    return (0);
}