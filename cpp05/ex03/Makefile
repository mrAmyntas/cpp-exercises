NAME =		ex03
CC =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98
SRC =		src/main.cpp\
			src/AForm.cpp\
			src/PresidentialPardonForm.cpp\
			src/Bureaucrat.cpp\
			src/RobotomyRequestForm.cpp\
			src/Intern.cpp\
			src/ShrubberyCreationForm.cpp
INC = 		inc/AForm.hpp\
			inc/PresidentialPardonForm.hpp\
			inc/Bureaucrat.hpp\
			inc/RobotomyRequestForm.hpp\
			inc/Intern.hpp\
			inc/ShrubberyCreationForm.hpp
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