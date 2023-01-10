SRCS = 	main.c \
		operations.c \
		utiles_sort.c \
		small_sort.c \
		big_sort.c \
		utiles1.c \
		utiles2.c \
		utiles3.c \
		utiles4.c \

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f

O_SRCS = $(SRCS:%.c=%.o)

$(NAME): $(O_SRCS)
	ar -rc $(NAME) $(O_SRCS)

all: $(NAME)
	cc  $(NAME) ../libft/libft.a -o push_swap


clean:
	$(RM) $(O_SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re