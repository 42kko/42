# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kko <kko@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:22:25 by seokchoi          #+#    #+#              #
#    Updated: 2023/01/02 15:07:57 by kko              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c init.c philo.c utils.c waiting.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME    = philo
HEAD	= includes
LIBFT	= libft

all:		${NAME}

.c.o:		${SRCS}
			${CC} $(CFLAGS) -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) -I $(HEAD) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re