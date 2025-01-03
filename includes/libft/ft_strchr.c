/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:19:12 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:47:38 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Searches `str` 'char by char' to find the first instance/occurence of `c`.
/// RETURN(s):
/// `NULL` - if `c` does not exist inside `str` 
/// `char *` - (memory address within `str` where `c` is) on success.
char	*ft_strchr(const char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return ((char *)--str);
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
