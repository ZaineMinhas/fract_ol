# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 19:22:42 by zminhas           #+#    #+#              #
#    Updated: 2021/07/06 17:11:33 by zminhas          ###   ########.fr        #
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
			srcs/zoom.c\
			srcs/utils.c\
			srcs/julia.c\
			srcs/init_var.c\
			srcs/mandelbrot.c\
			srcs/fract_name.c\

SRCS_BONUS	=	fractol_bonus.c\
				srcs_bonus/key.c\
				srcs_bonus/draw.c\
				srcs_bonus/move.c\
				srcs_bonus/zoom.c\
				srcs_bonus/utils.c\
				srcs_bonus/julia.c\
				srcs_bonus/init_var.c\
				srcs_bonus/mandelbrot.c\
				srcs_bonus/fract_name.c\

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME	=	fractol.a

LIB_PATH	=	./libft

.c.o:
				@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
					@make -C $(LIB_PATH)
					@cp -r $(LIB_PATH)/libft.a ./fractol.a
					@ar -rcs $(NAME) $(OBJS)
					@gcc -lmlx -framework OpenGL -framework AppKit $(NAME)
					@mv a.out fractol
					@echo "${GREEN}fractol.a created !${RESET}"

all:			$(NAME)

bonus:			$(OBJS_BONUS)
					@make -C $(LIB_PATH)
					@cp -r $(LIB_PATH)/libft.a ./fractol.a
					@ar -rcs $(NAME) $(OBJS_BONUS)
					@gcc -lmlx -framework OpenGL -framework AppKit $(NAME)
					@mv a.out fractol
					@echo "${BLUE}fractol_bonus.a created !${RESET}"

clean:			
				@rm -f $(OBJS)
				@rm -f $(OBJS_BONUS)
				@make clean -C ${LIB_PATH}
				@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
				@rm -f $(OBJS)
				@rm -f $(OBJS_BONUS)
				@rm -f $(NAME)
				@make fclean -C ${LIB_PATH}
				@echo "${RED}fclean done !${RESET}"

re:				fclean all

.PHONY:			all bonus clean fclean re