/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my_lib.h"

static int strlen_array(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\t'
            && str[i + 1] != '\0'))
            || (str[i] == '\t' && (str[i + 1] != ' ' && str[i + 1] != '\t'
            && str[i + 1] != '\0')))
            len += 1;
    }
    return (len + 1);
}

static char *find_alpha(char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] == ' ' || str[i] == '\t')
        i += 1;
    if (str[i] == '\0')
        return (NULL);
    return (&str[i]);
}

static int find_word(char *str)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
        i += 1;
    return (i);
}

static char **malloc_array(char **array, char *str)
{
    int count = 0;
    int size = 0;
    int i = 0;

    str = find_alpha(&str[size]);
    i = strlen_array(str);
    array = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j += 1) {
        str = find_alpha(&str[size]);
        size = find_word(str);
        array[j] = malloc(sizeof(char) * (size + 1));
        while (count < size) {
            array[j][count] = str[count];
            count += 1;
        }
        array[j][count] = '\0';
        count = 0;
    }
    array[i] = NULL;
    return (array);
}

char **my_str_to_word_array(char const *src)
{
    char **array = NULL;
    char *str = NULL;

    if (src == NULL || src[0] == '\0')
        return (NULL);
    str = malloc(sizeof(char) * my_strlen(src) + 1);
    str = my_strcpy(str, src);
    array = malloc_array(array, str);
    free(str);
    return (array);
}
