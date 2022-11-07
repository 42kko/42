NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c parsing.c exec.c parsing_util1.c getline.c \
free.c heredoc.c
SRCS_B = pipex_bonus.c parsing.c exec.c parsing_util1.c getline.c \
free.c heredoc.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJS_F = $(OBJS_B)
else
	OBJS_F = $(OBJS)
endif

all: ft_libft $(NAME)

bonus :
	make WITH_BONUS=1

ft_libft:
	make -C ./libft

$(NAME): $(OBJS_F)
	$(CC) $(CFLAGS) $(OBJS_F) -Llibft -lft -o $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJS_B) $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
