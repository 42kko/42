NAME = push_swap
CC = cc
CFALGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = -Llibft -lft

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

$(NAME) : ft_libft
	$(CC) $(OBJS) push_swap.o $(LIBFT) -o $(NAME)

all : $(NAME)

ft_libft :
	make -C libft

clean :
	make -C libft clean
	rm -f $(NAME)

fclean : clean

