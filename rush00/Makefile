NAME = ft_retro
CPPC = clang++
CFLAGS = -lcurses -Wall -Wextra -Werror
SRC = Thing.cpp Player.cpp Bullet.cpp Enemy.cpp BEnemy.cpp LEnemy.cpp PEnemy.cpp Win.cpp main.cpp 
OBJ = $(SRC:.cpp=.o)

$(NAME):
	@$(CPPC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
