NAME =		phonebook
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		src/PhoneBook.cpp\
			src/Contact.cpp\
			src/main.cpp

INC =		inc/PhoneBook.hpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -I/inc -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re