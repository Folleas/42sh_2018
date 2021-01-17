/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_puterror
*/

#include <unistd.h>

int my_puterror(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i += 1;
    }
    return (0);
}
