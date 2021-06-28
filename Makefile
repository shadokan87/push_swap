
NAME		= push_swap
SRC			= ./src_push_swap/push_swap.c  ./src_push_swap/push_swap3.c \
			  ./src_push_swap/push_swap5.c ./src_push_swap/push_swap7.c ./src_push_swap/push_swap9.c \
				./src_push_swap/push_swap2.c ./src_push_swap/push_swap4.c \
			./src_push_swap/push_swap6.c ./src_push_swap/push_swap8.c ./src_push_swap/push_swapX.c \
			./src_common/common.c  ./src_common/common2.c ./src_common/common3.c \
		./src_common/common4.c	./src_common/common5.c ./src_common/common6.c ./src_common/common7.c ./src_common/common8.c ./src_common/common9.c\

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
OBJ			= $(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	@printf "[push_swap] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $(LIB) $@
	@printf "[push_swap] Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "[push_swap] Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@printf "[push_swap] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[push_swap] Removed push_swap binary!\n"
re: fclean all

.PHONY: all clean fclean re
