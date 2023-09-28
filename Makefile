CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

NAME_BONUS = fractol_bonus

SRC = fract_ol.c mandel.c julia.c parsing.c utils.c error.c sierpinski_bonus.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -s -C libft all
	@cp libft/libft.a .
	@make -s -C minilibx-linux all
	@cp minilibx-linux/libmlx.a .
	@$(CC) $(CFLAGS)  -o $(NAME) $(OBJ) libft.a libmlx.a -lX11 -lXext -lbsd -g3
	@echo "Compilation terminee !"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ)
	@make -s -C libft all
	@cp libft/libft.a .
	@make -s -C minilibx-linux all
	@cp minilibx-linux/libmlx.a .
	@$(CC) $(CFLAGS)  -o $(NAME_BONUS) $(OBJ) libft.a libmlx.a -lX11 -lXext -lbsd -g3
	@echo "Bonus cree !"

clean :
	@rm -f $(OBJ)
	@make -s -C libft clean
	@make -s -C minilibx-linux clean
	@echo "------->  Au revoir les .o."

fclean : clean
	@rm -f $(NAME) $(NAME_BONUS) libft.a libmlx.a
	@make -s -C libft fclean
	@echo "--------> Tout est a la poubelle, chef !"

re : fclean all

.PHONY : all clean fclean re