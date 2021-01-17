/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** sutrcutres for minishell
*/

#ifndef STRUCTURES_
#define STRUCTURES_

#include "enum.h"

typedef struct pipe_s {
    enum pipe_status status;
    int prev_fd;
    int pfd[2];
} pipe_t;

typedef struct data_s {
    pipe_t pipe;
    char **commands;
    char **cpy_env;
    char **builtins;
    char **path_array;
    int ret_exit;
    int ret_value;
} data_t;

#endif
