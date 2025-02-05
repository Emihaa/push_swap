CC = cc 
CFLAGS = -Wall -Werror -Wextra ##-g -fsanitize=address -fsanitize=undefined -fsanitize=leak
LIBFT = ./libft
NAME = push_swap

LIBS = $(LIBFT)/libft.a
SRC = src/push_swap.c src/check_arg.c

OBJS = $(SRC:.c=.o)

all: $(LIBFT)/libft.a $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

%.o: %.c fdf.h
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