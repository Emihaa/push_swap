CC = cc 
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft
NAME = push_swap

LIBS = $(LIBFT)/libft.a
SRC = src/push_swap.c src/check_arg.c src/operation_pushswap.c src/operation_reserve.c src/find_target.c src/return_values.c src/take_action.c src/operation_rotation.c src/utils.c src/calculate_cost.c

OBJS = $(SRC:.c=.o)

all: $(LIBFT)/libft.a $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re