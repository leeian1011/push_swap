/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:15:22 by ialee             #+#    #+#             */
/*   Updated: 2025/01/06 23:37:46 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h> 

// character operations
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_isascii(char c);
int		ft_isprint(char c);
int		ft_toupper(char c);
int		ft_tolower(char c);

// string operations
int		ft_atoi(const char *num);
long	ft_atol(const char *num);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
char	*ft_strchr(const char *str, char c);
char	*ft_strrchr(const char *str, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t len);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strtrim(const char *str1, const char *set);
char	**ft_split(const char *str, char c);
char	*ft_strmapi(const char *str, char (*fn)(unsigned int, char));
void	ft_striteri(char *str, void (*fn)(unsigned int, char*));

// memory operations
int		ft_memcmp(const void *buf1, const void *buf2, size_t len);
void	*ft_memset(void *buf, int c, size_t len);
void	*ft_bzero(void *buf, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *buf, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

// integer operations
char	*ft_itoa(int num);
char	*ft_ltoa(long num);

// output operations
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int num, int fd);

// singly-linked-list operations
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del_fn)(void *));
void	ft_lstclear(t_list **lst, void (*del_fn)(void *));
void	ft_lstiter(t_list *lst, void (*fn)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*fn)(void *), void (*del_fn)(void *));

// printf prototypes
# define CONVERSIONS "cspdiuxX%"
# define FLAGS "+# -0."
# define FLAG_PLUS_MASK 128
# define FLAG_HASH_MASK 64
# define FLAG_SPACE_MASK 32
# define FLAG_DASH_MASK 16
# define FLAG_ZERO_MASK 8
# define FLAG_DOT_MASK 4
# define FLAG_NEGATIVE_INTEGER_MASK 2
# define FLAG_VALID_MASK 1
# define FLAG_ZERO_DOT_MASK 12
# define ARG_BUFFER_SIZE 4096 
# define HEX_MAX_LENGTH 8
# define HEX_PREFIX "0x"

typedef struct s_fmt {
	char			conversion;
	const char		*original;
	unsigned char	flag_mask;
	size_t			width_len;
	size_t			original_len;
	size_t			precision_len;
	char			*buf;
}	t_fmt;

/// fmt
void	initialize_fmt(t_fmt *fmt);
size_t	num_places(long num);
int		is_nonzero_digit(char c);
int		fmt_string(t_fmt *fmt, char *str);
int		fmt_char(t_fmt *fmt, char c);
int		fmt_ptr(t_fmt *fmt, ulong ptr);
int		fmt_integer(t_fmt *fmt, long integer);
int		fmt_hex(t_fmt *fmt, uint hex);
int		print_fmt(t_fmt *fmt, va_list *v_arg);

/// fmt util
void	fmthex_flag_util(t_fmt *fmt, size_t *index, char *num, size_t hex_len);
void	fmtptr_putil(t_fmt *fmt, long precision_len, long hex_len, size_t *idx);
int		fmtstr_zutil(t_fmt *fmt, size_t index, long len, char *arg);
size_t	fmtint_width_util(t_fmt *fmt, size_t sz, long num, char *int_str);
void	fmtint_flag_util(t_fmt *fmt, size_t *idx, long width_len, long arg_len);

/// Specifier handling for ft_printf (util). 
int		handle_specifiers(const char **str, va_list *v_arg);

int		ft_printf(const char *str, ...);

// get_next_line prototypes
# define BUFFER_SIZE 1024

// String parsing utils
char	*ft_strtonl(char *str);
char	*ft_strchrnl(char *str);

char	*get_next_line(int fd);
#endif
