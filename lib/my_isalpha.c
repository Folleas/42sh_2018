/*
** EPITECH PROJECT, 2019
** PISCINE
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
        return (1);
    return (0);
}
