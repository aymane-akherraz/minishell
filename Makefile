NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRC = main.c list_funcs.c
OBJ = $(SRC:%.c=%.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $@ $^ $(LIBFT) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cd libft && make $@
	$(RM) $(OBJ)

fclean: clean
	cd libft && make $@
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
