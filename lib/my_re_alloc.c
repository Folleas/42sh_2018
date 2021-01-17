/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_re_alloc
*/

#include <stdlib.h>

char *re_alloc(char *buff, int size, int new_size)
{
    char *str = malloc(sizeof(char) * (new_size + 1));
    int i = 0;

    if (str == NULL || new_size == 0) {
        free(str);
        return (NULL);
    }
    while (i < size) {
        str[i] = buff[i];
        i += 1;
    }
    free(buff);
    str[i] = '\0';
    return (str);
}
