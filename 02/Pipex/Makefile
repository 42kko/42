NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c parsing.c exec.c parsing_util1.c getline.c \
free.c heredoc.c
OBJS = $(SRCS:.c=.o)

all: ft_libft $(NAME)

ft_libft:
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
