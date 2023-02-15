# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:04:13 by selbakya          #+#    #+#              #
#    Updated: 2023/02/07 20:03:24 by selbakya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = #-Wall -Wextra -Werror

MY_LIB = ./libft

HEADER = ft_printf.h  
HEADER_BONUS = ft_printf_bonus.h  

SOURCES = $(wildcard *.c | grep -v "bonus" )
SOURCES_BONUS = $(wildcard *.c | grep "bonus")

OBJECTS = $(SOURCES:.c=.o)
OBJ_BONUS = $(SOURCES_BONUS:.c=.o)

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

.PHONY: all bonus clean fclean re norm

all: $(NAME)	
	@echo $?

$(NAME): $(OBJECTS) $(HEADER)
	@$(MAKE) --directory=./libft
	@ar -rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\n$(BLUE1)     Ft_printf functions was created \n$(RESET)"

bonus: $(OBJ_BONUS) $(HEADER_BONUS)
	@$(MAKE) --directory=$(MY_LIB)
	@ar -rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\n$(CYAN)     Ft_printf with bonus functions was created \n$(RESET)"

clean:  
	@$(MAKE) --directory=$(MY_LIB) clean
	@echo "$(PINK) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@echo 
	@echo "$(NAME): $(PINK)    object files were deleted $(RESET)"
	@echo 
	@echo "$(PINK) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

fclean: clean
	@$(MAKE) --directory=$(MY_LIB) fclean
	@rm -f $(NAME)
	@echo "$(PINK) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@echo 
	@echo "$(NAME):$(PINK)            deleted $(RESET)"
	@echo 
	@echo "$(PINK) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

re: fclean all

norm:
	@echo "$(GREEN) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~  Norminette  ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ \n$(RED)\c"
	@echo
	@norminette $(SOURCES) $(BONUS_SRC) $(HEADER) | grep "Error" -B1 || true
	@echo
	@echo "$(GREEN) ~~~ If there is nothing above, all files respect the $(RED)Norm$(GREEN) ~~~\n$(RESET)\c"
