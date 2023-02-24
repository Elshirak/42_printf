# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:04:13 by selbakya          #+#    #+#              #
#    Updated: 2023/02/24 16:21:52 by selbakya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFTD = libft/
LIBFT := ${addprefix ${LIBFTD},libft.a}
LIBFTMK = make -C $(LIBFTD)

CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SOURCE	=	ft_printf.c	utilc.c
HEADER	=	ft_printf.h

OBJECT	=	$(SOURCE:.c=.o)

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE1 = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECT) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJECT) $?
	@echo "$(BLUE1) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@echo "\n$(BLUE1)                 libftprintf created \n$(RESET)"
	@echo "$(BLUE1) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

$(LIBFT):
	$(LIBFTMK)
	
clean: 
	@rm -rf $(OBJECT)
	@$(LIBFTMK) clean 
	@echo "$(GREEN) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@echo 
	@echo "$(NAME): $(GREEN)    object files were deleted $(RESET)"
	@echo 
	@echo "$(GREEN) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

fclean: clean
	@rm -rf $(NAME)
	@$(LIBFTMK) fclean 
	@echo "$(GREEN) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@echo 
	@echo "$(NAME):$(GREEN)            deleted $(RESET)"
	@echo 
	@echo "$(GREEN) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

re:
	@$(MAKE) fclean
	@$(MAKE) all
