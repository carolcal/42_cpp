# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 16:53:49 by cayamash          #+#    #+#              #
#    Updated: 2025/07/28 11:33:34 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================== NAME ==================#
NAME = Iter

#=========== COMPILERS AND FLAGS ===========#
CC = c++
FLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

#=============== DIRECTORIES ===============#
INCLUDES = -I inc
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = main.cpp
SRC  =$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

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
	$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Compiled!$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)


.PHONY: all clean fclean re