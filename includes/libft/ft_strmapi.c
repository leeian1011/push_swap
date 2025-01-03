/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:06:31 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:02:12 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Creates a new string, which value is created by iterating over `str`
/// and applying `fn` on all produced `char` .
/// This function allocates a maximum of ft_strlen(str) + 1 onto the heap.
/// RETURN(s):
///	`NULL` - on failure to allocate memory
///	`char *` - (new `char *` allocated) that on success
char	*ft_strmapi(const char *str, char (*fn)(unsigned int, char))
{
	char	*result;
	size_t	index;

	index = 0;
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	while (*str)
	{
		result[index] = fn(index, *str++);
		index++;
	}
	result[index] = '\0';
	return (result);
}
