NAME	=	ft_gkrellm
CC		=	clang++
CFLAGS	=	-O2 -Wall -Wextra -Werror -std=c++98 -pedantic -lncurses
SRC		=	*.cpp
OBJ		=	$(SRC:.cpp=.o)

GRAPHICS = -I ./minilibx_macos -L ./minilibx_macos -lmlx -framework OpenGL -framework Appkit \
-g ./minilibx_macos/libmlx.a

$(NAME):
	@$(CC) $(CFLAGS) $(GRAPHICS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all