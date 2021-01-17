/*
** EPITECH PROJECT, 2018
** GET_NEXT_LINE
** File description:
** function
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char *my_re_alloc(char *buff, int size, int new_size)
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
    return (str);
}

static char my_getchar(int fd)
{
    static char buff[READ_SIZE];
    static char *tmp;
    static unsigned int i = 0;
    char c;

    if (i == 0) {
        i = read(fd, buff, READ_SIZE);
        tmp = buff;
        if (i == 0)
            return ('\0');
    }
    c = *tmp;
    tmp += 1;
    i -= 1;
    return (c);
}

static char *check_end_str(int j, char c, char *buff)
{
    static int i = 0;

    if (c == '\0' && buff[j] == '\0' &&  i == 0 && j != 0)
        i += 1;
    else if (c == '\0' && buff[j] == '\0') {
        free(buff);
        return (0);
    }
    return (buff);
}

char *get_next_line(int fd)
{
    char c = my_getchar(fd);
    char *buff = malloc(sizeof(char) * (READ_SIZE + 1));
    int nb_loop = 1;
    int i = 0;

    if (buff == NULL || fd == -1)
        return (NULL);
    while (c != '\n' && c != '\0') {
        if (i >= (READ_SIZE * nb_loop)) {
            nb_loop += 1;
            buff = my_re_alloc(buff, i, (READ_SIZE * nb_loop + 1));
        }
        buff[i] = c;
        c = my_getchar(fd);
        i += 1;
    }
    buff[i] = '\0';
    return (check_end_str(i, c, buff));
}
