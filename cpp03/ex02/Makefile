NAME =		ClapTrap
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		src/main.cpp\
			src/ClapTrap.cpp\
			src/ScavTrap.cpp\
			src/FragTrap.cpp
INC = 		inc/ClapTrap.hpp\
			inc/ScavTrap.hpp\
			inc/FragTrap.hpp
SRC_DIR =	src/
OBJ_DIR = 	obj/
OBJ =		$(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)
		$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR): 
	mkdir $(OBJ_DIR)

clean:
	rm -f obj/*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

