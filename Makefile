SRCS = 	main.c \
		operations.c \
		utiles.c \
		utiles_sort.c \
		small_sort.c \

#CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f

O_SRCS = $(SRCS:%.c=%.o)

all: $(NAME)
	cc  $(NAME) libft/libft.a -o push_swap

$(NAME): $(O_SRCS)
	ar -rc $(NAME) $(O_SRCS)

clean:
	$(RM) $(O_SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re