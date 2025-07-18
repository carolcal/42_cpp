# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 16:53:49 by cayamash          #+#    #+#              #
#    Updated: 2025/07/15 10:34:18 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================== NAME ==================#
NAME = zombie

#=========== COMPILERS AND FLAGS ===========#
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

#=============== DIRECTORIES ===============#
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

#================== STYLE ==================#
GREEN = \033[1;32m
END = \033[0m

#================== RULES ==================#
all: $(OBJ_DIR) $(NAME)
	
clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Cleaned$(END)"

fclean: clean
	rm -f $(NAME)
	@echo "$(GREEN)All!$(END)"
	
re: fclean all

#================ EXECUTABLE ================#
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Compiled!$(END)"

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@
	

.PHONY: all clean fclean re