/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my_lib.h"

char *my_strcat(char *dest, char const *src)
{
    int len = 0;
    int i = 0;

    if (dest == NULL || dest[0] == '\0')
        len = 0;
    else
        len = my_strlen(dest);
    while (src[i] != '\0') {
        dest[len] = src[i];
        i += 1;
        len += 1;
    }
    dest[len] = '\0';
    return (dest);
}
