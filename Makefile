##
## EPITECH PROJECT, 2018
## Piscine_2018
## File description:
## Makefile
##

NAME		=	42sh

CPPFLAGS	+=	-Iinclude/ -g

CFLAGS		+=	-W -Wall

LIB		=	-L./lib/ -lmy

SRC		=	src/pipes_management/utils_pipe.c\
			src/pipes_management/pipe.c\
			src/commands_management/multiples_commands.c\
			src/commands_management/commands_utils_exec.c\
			src/signal.c\
			src/builtins_commands/unsetenv_commands.c\
			src/builtins_commands/setenv_commands.c\
			src/builtins_commands/exit_commands.c\
			src/builtins_commands/cd_commands.c\
			src/builtins_commands/env_commands.c\
			src/builtins_commands/find_builtins.c\
			src/builtins_commands/initialize_builtins.c\
			src/commands_management/commands_exec.c\
			src/prompt.c\
			src/path_management/copy_path.c\
			src/minishell.c\
			src/main.c

OBJS		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			make -C lib/
			gcc -o $(NAME) $(OBJS) $(LIB)

clean:
			$(RM) $(OBJS)
			make clean -C lib/

fclean:			clean
			make fclean -C lib/
			$(RM) $(NAME)


re:			fclean all

.PHONY:			all clean fclean re
