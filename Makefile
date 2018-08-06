# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francoismaury <francoismaury@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2018/08/04 00:36:54 by francoismau      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= wolf3d

COMPILER		= gcc

CC_FLAGS		= -Wall -Werror -Wextra -Wconversion -g
INC				= ./includes/

SRC_DIR			= ./srcs

LIB_FLAG = -framework OpenGL -framework AppKit ./minilibx_macos/libmlx.a

LIBNUX_FLAG = -L/usr/X11/lib -lXext -lX11 ./minilibx_linux/libmlx.a

SRC				=	main.c \
					ft_parse.c \
					ft_wolf.c \
					ft_tools.c \
					dda_algo.c \
					multi_thread.c

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
	@$(COMPILER) $(CC_FLAGS) $(OBJ) $(LIB_FLAG) -lm ./libft/libft.a -o $(NAME)
	@$(NEWLINE)
	@echo "wolf3d cree !"
	$(NEWLINE)

%.o: $(SRC_DIR)/%.c
	@$(COMPILER) $(CC_FLAGS) -I $(INC) -c $< -o $@

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
