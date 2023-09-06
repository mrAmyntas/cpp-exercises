NAME =		Zoo
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		src/main.cpp\
			src/AMateria.cpp\
			src/Ice.cpp\
			src/Cure.cpp\
			src/Character.cpp\
			src/ICharacter.cpp\
			src/MateriaSource.cpp

INC =		inc/AMateria.hpp\
			inc/Character.hpp\
			inc/Cure.hpp\
			inc/Ice.hpp\
			inc/ICharacter.hpp\
			inc/IMateriaSource.hpp\
			inc/MateriaSource.hpp\

SRC_DIR =	src/
OBJ_DIR = 	obj/
OBJ =		$(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
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
