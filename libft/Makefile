CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
	ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c get_next_line.c\
	get_next_line_utils.c ft_conv_base.c ft_putadd.c ft_unsigned_conv_base.c ft_printf.c \
	ft_putunsigned_nbr_fd.c ft_param_len.c ft_putstr_free_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstlast.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar cr $(NAME) -o $^
	@echo "La libft est prete !"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $^


clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
