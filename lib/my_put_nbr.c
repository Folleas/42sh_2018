/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_put_nbr
*/

#include "my_lib.h"

int my_put_nbr(long long nb)
{
    long long var1 = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        var1 = (nb % 10);
        nb = (nb - var1) / 10;
        my_put_nbr(nb);
        my_putchar(48 + var1);
    }
    else
        my_putchar(48 + nb);
    return (0);
}
