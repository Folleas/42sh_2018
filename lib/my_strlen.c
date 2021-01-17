/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i] != '\0')
        i += 1;
    return (i);
}
