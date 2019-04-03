NAME = phonebook
CC = clang++
CFLAGS = -Wall -Wextra -Werror
SRC = Contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
