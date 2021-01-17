/*
** EPITECH PROJECT, 2018
** Piscine_2018
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i + 1] == '\0' && s2[i + 1] == '\0')
            return (0);
        i += 1;
    }
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}
