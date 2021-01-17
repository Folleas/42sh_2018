/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** main for minishell
*/

#include <stdlib.h>
#include "my_lib.h"
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    (void)argv;

    if (argc != 1) {
        my_puterror("Error: bad arguments\n");
        return (84);
    }
    return (minishell(env));
}
