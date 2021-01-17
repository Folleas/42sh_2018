/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** prompt gestion
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my_lib.h"
#include "minishell.h"

void display_prompt(void)
{
    char prompt[FILENAME_MAX];
    int i = 0;
    int count = 0;

    getcwd(prompt, FILENAME_MAX);
    i = my_strlen(prompt);
    my_putchar('[');
    while (count < 1) {
        if (prompt[i] == '/')
            count += 1;
        i -= 1;
    }
    i += 1;
    for (; prompt[i] != '\0'; i += 1)
        my_putchar(prompt[i]);
    my_putstr("]$> ");
}
