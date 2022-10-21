NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c get_map.c map_object1.c map_object2.c map_utile.c \
	move.c util1.c util2.c check1.c check2.c err.c util3.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx -lmlx \
	-framework OpenGl -framework AppKit  -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean -C ./minilibx

re: fclean all
