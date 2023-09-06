NAME =		run_tests
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		Account.cpp\
			tests.cpp
INC =		Account.hpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -I. -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re