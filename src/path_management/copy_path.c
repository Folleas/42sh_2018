/*
** EPITECH PROJECT, 2019
** MINISHELL ONE
** File description:
** management path minishell
*/

#include <stdlib.h>
#include "my_lib.h"
#include "minishell.h"

static char **path_hard(void)
{
    char **path_array = malloc(sizeof(char *) * 5);

    if (path_array == NULL)
        return (NULL);
    path_array[0] = my_strdup("/usr/local/sbin");
    path_array[1] = my_strdup("/usr/local/bin");
    path_array[2] = my_strdup("/usr/bin");
    path_array[3] = my_strdup("/bin");
    path_array[4] = NULL;
    return (path_array);
}

char **copy_path(char **tmp_env, char **path)
{
    char **path_array = NULL;

    for (int i = 0; tmp_env[i] != NULL; i += 1) {
        if (my_strncmp(tmp_env[i], "PATH=", 5) == 0 && tmp_env[i][5] != '\0') {
            path_array = my_str_to_word_pimp(&tmp_env[i][5], ':');
            free_array(path);
            return (path_array);
        }
    }
    return (path_hard());
}

char **copy_path_env(char **env)
{
    char **path_array = NULL;

    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            path_array = my_str_to_word_pimp(&env[i][5], ':');
            return (path_array);
        }
    }
    return (path_hard());
}
