CC = gcc

INC = includes
SRC = srcs
NAME = libft.a
FLAG = -Wall -Werror -Wextra

SRCS = $(SRC)/ft_putchar.c $(SRC)/ft_swap.c $(SRC)/ft_putstr.c $(SRC)/ft_strlen.c $(SRC)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@ -I $(INC)

$(NAME): $(OBJS)
	ar cr $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
