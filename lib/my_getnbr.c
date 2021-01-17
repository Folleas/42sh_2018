/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_getnbr
*/

#include <stdlib.h>

int my_getnbr(char const *str)
{
    int count = 0;
    int sign = 1;
    long max = 0;

    if (str == NULL || str[0] == '\0')
        return (0);
    while (str[count] < '0' || str[count] > '9') {
        if (str[count] == '-')
            sign *= -1;
        count += 1;
    }
    while (str[count] >= '0' && str[count] <= '9') {
        max *= 10;
        max = max + (str[count] - '0');
        count += 1;
        if (max < -2147483647 || max > 2147483647)
            return (0);
    }
    count = max;
    return (count * sign);
}
