NAME =		Zoo
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		src/main.cpp\
			src/Animal.cpp\
			src/Dog.cpp\
			src/Cat.cpp\
			src/Brain.cpp

INC = 		inc/Animal.hpp\
			inc/Dog.hpp\
			inc/Cat.hpp\
			inc/Brain.hpp

all: $(NAME) $(INC)

$(NAME): $(SRC) $(INC)
	$(CC) $(CFLAGS) $(SRC) -I./inc -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
