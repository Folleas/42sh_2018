/*
** EPITECH PROJECT, 2019
** INCLUDE
** File description:
** lib mytabcpy
*/

#include <stdlib.h>
#include "my_lib.h"

char **my_tabcpy(char **array)
{
    char **tab = malloc(sizeof(char *) * (count_array(array) + 1));
    int i = 0;

    if (tab == NULL)
        return (NULL);
    for (; array[i] != NULL; i += 1) {
        tab[i] = my_strdup(array[i]);
        if (tab[i] == NULL)
            return (NULL);
    }
    tab[i] = NULL;
    return (tab);
}
