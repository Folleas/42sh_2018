##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Day10
##

NAME	=	libmy.a

CFLAGS	+=	-W -Wall

CPPFLAGS +=	-I../include/

SRC	=	my_count_array.c\
		my_tabcpy.c\
		my_isalpha_num.c\
		my_isalpha.c\
		my_re_alloc.c\
		my_str_to_word_pimp.c\
		my_str_to_word_array.c\
		my_strncmp.c\
		my_strdup.c\
		my_strcpy.c\
		my_strcmp.c\
		my_strcat.c\
		my_getnbr.c\
		get_next_line.c\
		my_put_nbr.c\
		my_puterror.c\
		my_strlen.c\
		my_putstr.c\
		my_putchar.c

OBJS	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
