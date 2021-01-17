/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** initialize builtins
*/

#include <stdlib.h>
#include "my_lib.h"

char **initialize_builtins(void)
{
    char **builtins = malloc(sizeof(char *) * 6);

    if (builtins == NULL)
        return (NULL);
    builtins[0] = my_strdup("cd");
    builtins[1] = my_strdup("setenv");
    builtins[2] = my_strdup("unsetenv");
    builtins[3] = my_strdup("env");
    builtins[4] = my_strdup("exit");
    builtins[5] = NULL;
    return (builtins);
}
