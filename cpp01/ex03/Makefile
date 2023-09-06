NAME =		violence
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		src/main.cpp\
			src/HumanA.cpp\
			src/HumanB.cpp\
			src/Weapon.cpp
INC =		inc/HumanA.hpp\
			inc/HumanB.hpp\
			inc/Weapon.hpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -I/inc -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
