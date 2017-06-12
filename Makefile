NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c srcs/creare.c srcs/functii.c srcs/resetare.c \
	  srcs/rezolvare.c srcs/checker.c
OBJ = main.o creare.o functii.o resetare.o rezolvare.o checker.o
INCL = includes/

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -I $(INCL) -c $(SRC)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)
clean:
	make -C libft/ fclean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
