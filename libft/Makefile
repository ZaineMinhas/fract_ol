# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 18:35:49 by zminhas           #+#    #+#              #
#    Updated: 2021/06/25 16:49:28 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	ft_strlen.c

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

.c.o:
			@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}
			@echo "${LIGHTPURPLE}Compilation of :$<${RESET}"

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@echo "${GREEN}Library created !${RESET}"

all:		${NAME}

clean:
			@rm -f ${OBJS}
			@rm -f ${OBJS_BONUS}

fclean:
			@rm -f ${OBJS}
			@rm -f ${NAME}
			@rm -f ${OBJS_BONUS}

re:			fclean all

.PHONY:		all clean fclean re bonus