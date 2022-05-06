NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c print_add.c print_digit.c print_char.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make all -C ../$(LIBFT)
	cp ../$(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

libft :
	make fclean -C ../$(LIBFT)

re : clean all

.PHONY : all clean fclean re
