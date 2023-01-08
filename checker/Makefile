SRCS =	get_next_line.c \
		get_next_line_utils.c \
		main.c \
		operations.c \
		utiles1.c \
		utiles2.c \

NAME = checker
RM = rm -f

O_SRCS = $(SRCS:%.c=%.o)

$(NAME): $(O_SRCS)
	ar -rc $(NAME) $(O_SRCS)

all: $(NAME)
	cc  $(NAME)  ../libft/libft.a  -o checker


clean:
	$(RM) $(O_SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
