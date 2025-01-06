NAME=push_swap
LIBFT_PATH=includes/libft/
CC_FLAGS=-Wall -Wextra -Werror
SOURCE=\
	   src/stack/list.c src/stack/list_utils.c src/stack/stack.c src/stack/stack_utils.c src/stack/stack_collection.c src/stack/stack_operations.c \
	   src/stack/stack_seek.c src/sorting/sort.c src/sorting/sort_5.c src/sorting/brute_force.c src/sorting/brute_force_utils.c src/input.c
BONUS_SOURCE=\
	   src/stack/list.c src/stack/list_utils.c src/stack/stack.c src/stack/stack_utils.c src/stack/stack_collection.c src/stack/stack_operations.c \
	   src/stack/stack_seek.c src/sorting/sort.c src/sorting/sort_5.c src/sorting/brute_force.c src/sorting/brute_force_utils.c src/input.c \
	   src/checker_util.c

all: $(NAME) 

$(NAME): libft.a
	cc $(CC_FLAGS) src/push_swap.c $(SOURCE) $(LIBFT_PATH)libft.a -o $(NAME)

bonus: libft.a
	cc $(CC_FLAGS) src/checker.c $(BONUS_SOURCE) $(LIBFT_PATH)libft.a -o checker

libft.a:
	make re -C $(LIBFT_PATH)

clean:
	rm -rf *.o

fclean: clean
	rm -rf push_swap

re: fclean all

.PHONY:
	$(NAME) libft.a bonus clean fclean re all
