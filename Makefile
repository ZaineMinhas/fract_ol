# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 19:22:42 by zminhas           #+#    #+#              #
#    Updated: 2021/06/22 19:12:45 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	fractol.c\
			srcs/key.c\
			srcs/draw.c\
			srcs/move.c\
			srcs/zoom.c\
			srcs/utils.c\
			srcs/init_var.c\
			srcs/mandelbrot.c\

OBJS	=	${SRCS:.c=.o}

NAME	=	fractol.a

LIB_PATH	=	./libft

.c.o:
				@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
					@make -C $(LIB_PATH)
					@cp -r $(LIB_PATH)/libft.a ./fractol.a
					@ar -rcs $(NAME) $(OBJS)
					@gcc -lmlx -framework OpenGL -framework AppKit $(NAME)
					@echo "${GREEN}fractol.a created !${RESET}"

all:			$(NAME)

clean:			
				@rm -f $(OBJS)
				@make clean -C ${LIB_PATH}
				@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
				@rm -f $(OBJS)
				@rm -f $(NAME)
				@make fclean -C ${LIB_PATH}
				@echo "${RED}fclean done !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re