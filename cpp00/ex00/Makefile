NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re