/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** my_lib.h
*/

#ifndef MYLIB_H_
#define MYLIB_H_

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_puterror(char const *str);
int my_put_nbr(long long nb);
int my_isalpha(char c);
int my_isalpha_num(char c);
char *get_next_line(int fd);
int my_getnbr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(char const *src);
char **my_str_to_word_pimp(char const *src, char c);
char *re_alloc(char *buff, int size, int new_size);
char **my_tabcpy(char **array);
int count_array(char **array);

#endif
