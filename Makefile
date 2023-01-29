# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 14:04:13 by selbakya          #+#    #+#              #
#    Updated: 2023/01/29 18:40:26 by selbakya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SOURCES = $(wildcard *.c)
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

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
	@echo "$(BLUE) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@ar -rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\n$(BLUE)                   lib created \n$(RESET)"
	@echo "$(BLUE) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

bonus: $(BONUS_OBJ) $(HEADER)
	@echo "$(BLUE) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@ar -rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\n$(BLUE)       lib with bonus functions was created \n$(RESET)"
	@echo "$(BLUE) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

clean:  
	@rm -rf $(BONUS_OBJ) $(OBJECTS)
	@echo "$(PINK) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"
	@echo 
	@echo "$(NAME): $(PINK)    object files were deleted $(RESET)"
	@echo 
	@echo "$(PINK) ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~\n$(RESET)\c"

fclean: clean
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
