/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:35 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:54:53 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Searches `str` 'char by char' to find the first instance/occurence of `c`
/// from the end of `str`.
/// RETURN(s):
/// `NULL` - if `c` does not exist inside `str` 
/// `char *` - (memory address within `str` where `c` is) on success.
char	*ft_strrchr(const char *str, char c)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
		if (*str++ == c)
			ptr = (char *)(str - 1);
	if (c == '\0')
		return ((char *)str);
	return (ptr);
}
