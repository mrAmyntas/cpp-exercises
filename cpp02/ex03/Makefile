NAME =		ex03
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		Fixed.cpp\
			main.cpp\
			Point.cpp\
			bsp.cpp
INC =		Fixed.hpp\
			Point.hpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -I/inc -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
