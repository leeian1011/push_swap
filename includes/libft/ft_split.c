/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:14:13 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:59:48 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

/// This is used to count the number of words there are 
/// inside of `str`.
static size_t	ft_strwrdc(const char *str, char c)
{
	size_t	len;
	int		is_word;

	len = 1;
	is_word = 1;
	if (*str == c)
		is_word = 0;
	while (*str)
	{
		if (*str++ == c && is_word)
		{
			len++;
			is_word = 0;
		}
		else
			is_word = 1;
	}
	return (len);
}

/// This is used to append the newly extracted `char *` into the 
/// `result` array.
static void	*ft_strappend(char **str, char *new_str, size_t index)
{
	if (!new_str)
	{
		while (index-- > 0)
			free(str[index]);
		free(str);
		return (NULL);
	}
	str[index] = new_str;
	return (*str);
}

/// This is used to handle initialization of values `index`
/// and `result`
static void	**ft_initialize(char ***result, size_t size, size_t *index)
{
	*result = malloc(sizeof(char *) * size);
	if (!result)
		return (NULL);
	*index = 0;
	return ((void *)*result);
}

/// Splits a string by `c` and returns an array of `char *`
/// This functions allocates a variable size onto the heap.
/// Example:
/// "Hello World !" -> ft_split -> [["Hello", "World", "!"]]
/// RETURN(s):
/// `NULL` - if memory allocation fails. 
/// `char **` - (array of split `char *` ) on success.
char	**ft_split(const char *str, char c)
{
	size_t	index;
	char	*next;
	char	**result;

	if (!ft_initialize(&result, ft_strwrdc(str, c) + 1, &index))
		return (NULL);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break ;
		next = ft_strchr(str, c);
		if (!next)
		{
			if (!ft_strappend(result, ft_strdup(str), index++))
				return (NULL);
			break ;
		}
		if (!ft_strappend(result, ft_substr(str, 0, (next - str)), index++))
			return (NULL);
		str = next;
	}
	result[index] = NULL;
	return (result);
}
