SRCS	=	ft_printf.c \
			ft_put_hex.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putchar_fd.c \
			ft_put_ptr_hex.c \
			ft_put_unsign_fd.c

OFILES	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -rf
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OFILES) 
		ar -rcs $@ $(OFILES)

%.o: %.c
	$(CC) -c ${CFLAGS}	$< -o $@

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
