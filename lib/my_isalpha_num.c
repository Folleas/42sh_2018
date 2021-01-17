/*
** EPITECH PROJECT, 2019
** PISCINE
** File description:
** my_isalpha_num
*/

int my_isalpha_num(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}
