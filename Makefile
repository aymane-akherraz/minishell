NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = main.c
OBJ = $(SRC:%.c=%.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $@ $^ $(LIBFT) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -lreadline

clean:
	cd libft && make $@
	$(RM) $(OBJ)

fclean: clean
	cd libft && make $@
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
