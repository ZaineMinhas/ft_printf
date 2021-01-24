# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 15:48:49 by zminhas           #+#    #+#              #
#    Updated: 2021/01/24 18:50:01 by zminhas          ###   ########.fr        #
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

SRCS	=	$(shell ls srcs/ | grep -E ".+\.c")

OBJS	=	$(addprefix srcs/, ${SRCS:.c=.o})

NAME	=	libftprintf.a

LIB_PATH	=	./libft

.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}
		@echo "${LIGHTPURPLE}Compilation of :$<${RESET}"

$(NAME):	${OBJS}
		@make -C ${LIB_PATH}
		@cp libft/libft.a ./${NAME}
		@ar -rcs ${NAME} ${OBJS}
		@ranlib ${NAME}
		@echo "${GREEN}libftprintf.a created !${RESET}"


all:	${NAME}

clean:
		@rm -f ${OBJS}
		@make clean -C ${LIB_PATH}
		@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
		@rm -f ${OBJS}
		@rm -f ${NAME}
		@make fclean -C ${LIB_PATH}
		@echo "${RED}fclean done !${RESET}"

allup:	re clean
		@clear
		
re:			fclean all

.PHONY:		all clean fclean re
