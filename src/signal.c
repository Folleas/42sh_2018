/*
** EPITECH PROJECT, 2019
** MINISHELL_ONE
** File description:
** signal management
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_lib.h"
#include "minishell.h"

void check_signal(int sig)
{
    (void)sig;

    my_putchar('\r');
    display_prompt();
    my_putstr("  \n");
    display_prompt();
}
