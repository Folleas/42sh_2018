/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my_lib.h"

static int strlen_array(char const *str, char c)
{
    int len = 0;

    if (my_strlen(str) == 0)
        return (1);
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c && (str[i + 1] != c || str[i + 1] != ' '
        || str[i + 1] != '\0'))
            len += 1;
    }
    return (len + 1);
}

static char *find_alpha(char *str, char c)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] == c || str[i] == ' ' || str[i] == '\t')
        i += 1;
    if (str[i] == '\0')
        return (NULL);
    return (&str[i]);
}

static int find_word(char *str, char c)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[i] != c && str[i] != '\0')
        i += 1;
    return (i);
}

static char **malloc_array(char **array, char *str, char c)
{
    int count = 0;
    int size = 0;
    int i = 0;

    str = find_alpha(&str[size], c);
    i = strlen_array(str, c);
    array = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; j < i; j += 1) {
        str = find_alpha(&str[size], c);
        size = find_word(str, c);
        array[j] = malloc(sizeof(char) * (size + 2));
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

char **my_str_to_word_pimp(char const *src, char c)
{
    char **array = NULL;
    char *str = NULL;

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * my_strlen(src) + 1);
    str = my_strcpy(str, src);
    array = malloc_array(array, str, c);
    free(str);
    return (array);
}
