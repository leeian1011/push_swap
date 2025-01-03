NAME = libft.a
SOURCE= \
		 		ft_strjoin.c ft_strnstr.c ft_strdup.c ft_putstr_fd.c ft_memcpy.c ft_memmove.c ft_strlen.c ft_strlcat.c \
				ft_bzero.c ft_atoi.c ft_strrchr.c ft_striteri.c ft_toupper.c ft_memcmp.c ft_split.c ft_itoa.c ft_strncmp.c \
				ft_memset.c ft_substr.c ft_strchr.c  ft_strtrim.c ft_isdigit.c ft_isalpha.c ft_calloc.c ft_atol.c \
				ft_isascii.c ft_isalnum.c ft_isprint.c ft_strmapi.c ft_putnbr_fd.c ft_strlcpy.c ft_memchr.c ft_putendl_fd.c \
				ft_putchar_fd.c ft_tolower.c ft_printf.c ft_fmthex.c ft_fmtstr.c ft_fmtptr.c ft_fmtint.c ft_fmt.c ft_ltoa.c \
				ft_printf_handler.c ft_fmt_utils.c get_next_line.c get_next_line_utils.c
BONUS = \
				ft_lstsize.c ft_lstmap.c  ft_lstadd_front.c ft_lstnew.c ft_lstiter.c ft_lstadd_back.c ft_lstclear.c \
				ft_lstlast.c ft_lstdelone.c 
OBJ = $(SOURCE:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(@) $(^)

%.o: %.c
	cc -Wall -Wextra -Werror -c $(<) -o $(@)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(^)

re: fclean $(NAME)

PHONY:
	all re clean fclean bonus
# `$(<)` represents the 'first prerequisite'
# `$(@)` represents the RULE name
# `$(^)` represents 'all prerequisites'
