/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** count array
*/

#include <stdlib.h>

int count_array(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i += 1;
    return (i);
}
