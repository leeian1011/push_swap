NAME=push_swap
LIBFT_PATH=./includes/libft/
SOURCE=\
			 src/stack/list.c src/stack/list_utils.c src/stack/stack.c src/stack/stack_utils.c src/stack/stack_collection.c src/stack/stack_operations.c\
			 src/sorting/sort.c src/sorting/sort_5.c src/sorting/brute_force.c src/sorting/brute_force_utils.c src/input.c

all: libft.a
	cc src/push_swap.c $(SOURCE) libft.a

libft.a:
	make re -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)libft.a .

bonus: libft.a
	cc src/checker.c $(SOURCE) libft.a

test:
	cc src/test.c $(SOURCE) libft.a
