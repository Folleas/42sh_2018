/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** multiple commands management
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_lib.h"
#include "minishell.h"
#include "structures.h"

int count_commands(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == ';')
            count += 1;
    return (count);
}

char **create_multi_commands(const char *str)
{
    char **tmp = NULL;

    if (str == NULL || str[0] == '\0')
        return (NULL);
    tmp = my_str_to_word_pimp(str, ';');
    return (tmp);
}