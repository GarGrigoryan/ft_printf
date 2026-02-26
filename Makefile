NAME = libftprintf.a

CC = cc

RM = rm -rf

AR = ar -rcs

CFLAG = -Wall -Werror -Wextra -c

SRC =	ft_printf.c \
		ft_putnbr_base.c \
		utils.c \
		ft_ptr.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAG) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
