NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ./ft_itoa_base.c ./ft_put_addr.c ./ft_printf.c ./ft_putchar.c ./ft_putnbr.c ./ft_putstr.c ./ft_putUnsigned.c 
FILES_O = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(FILES_O)
	ar -rc $(NAME) $?

.c.o: $(FILES_O)
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
