SRCS = 	srcs/main.c \
		srcs/operations.c \
		srcs/utiles_sort.c \
		srcs/small_sort.c \
		srcs/big_sort.c \
		srcs/utiles1.c \
		srcs/utiles2.c \
		srcs/utiles3.c \
		srcs/utiles4.c \
		srcs/ft_split.c \
		srcs/ft_atoi.c \
		srcs/ft_strlen.c \
		srcs/ft_isdigit.c \
		srcs/ft_substr.c \
		srcs/ft_strdup.c \
		srcs/ft_strncmp.c \

SRCS_B = 	checker_bonus/get_next_line_bonus.c \
		checker_bonus/get_next_line_utils_bonus.c \
		checker_bonus/main_bonus.c \
		checker_bonus/utiles1_bonus.c \
		checker_bonus/utiles2_bonus.c \
		checker_bonus/utiles3_bonus.c \
		checker_bonus/operations_bonus.c \
		srcs/ft_split.c \
		srcs/ft_atoi.c \
		srcs/ft_strlen.c \
		srcs/ft_isdigit.c \
		srcs/ft_substr.c \
		srcs/ft_strdup.c \
		srcs/ft_strncmp.c \

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECKER = checker
RM = rm -rf
CC = cc

O_SRCS = $(SRCS:%.c=%.o)
O_SRCS_B = $(SRCS_B:%.c=%.o)

all: $(NAME)

$(NAME): $(O_SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(O_SRCS_B)
	$(CC) $(CFLAGS) $(SRCS_B) -o $(CHECKER)

clean:
	$(RM) $(O_SRCS) $(O_SRCS_B)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re