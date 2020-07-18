NAME = libftprintf.a
SRC = ft_printf.c check.c types.c utils.c numbers.c floats.c

HEADER = ft_printf.h

OBJ	= $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -c

LIBFT = libft/libft.a

LIB_DIR = libft

INC_DIR = . libft

all: $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAG) -c $<

$(NAME): $(OBJ)	
	make -C $(LIB_DIR)
	ar rc $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
