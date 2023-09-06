NAME =		zombies
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		main.cpp\
			Zombie.cpp\
			ZombieHorde.cpp
			

INC =		Zombie.hpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -I/inc -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
