/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my_lib.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);

    if (src == NULL || str == NULL) {
        free(str);
        return (NULL);
    }
    str = my_strcpy(str, src);
    return (str);
}
