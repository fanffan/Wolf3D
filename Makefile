#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaury <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2018/06/07 16:21:13 by fmaury           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= wolf3d

COMPILER		= gcc

CC_FLAGS		= -Wall -Werror -Wextra -g

INC				= ./includes/wolf.h

SRC_DIR			= ./srcs

SRC				=	main.c \

OBJ				= $(SRC:.c=.o)

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))

NEWLINE			= @echo ""

all : $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(NEWLINE)
	@echo "Compilation de la libft..."
	@MAKE -C libft/
	@$(NEWLINE)
	@echo "Compilation du wolf3d..."
	@$(COMPILER) $(CC_FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)
	@$(NEWLINE)
	@echo "wolf3d cree !"
	$(NEWLINE)

%.o: $(SRC_DIR)/%.c
	@$(COMPILER) $(CC_FLAGS) -c $< -o $@

clean:
	@echo "Suppression des objets"
	$(NEWLINE)
	@MAKE clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@echo "Suppression de l'executable"
	$(NEWLINE)
	@MAKE fclean -C libft/
	@rm -rf $(NAME)

re: fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
