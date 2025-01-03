/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:39:43 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:52:17 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Searches up to `len` bytes in the memory buffer `buf`
/// for the first byte that has the same value as 'c'.
/// RETURN(s):
/// `NULL` - if `c` does not exist in `buf` 
/// `void *` - (memory address within `buf` where `c` is found) on success. 
void	*ft_memchr(const void *buf, int c, size_t len)
{
	const unsigned char	*ptr;

	ptr = buf;
	while (len-- > 0)
		if ((unsigned char)*ptr++ == (unsigned char)c)
			return ((void *)--ptr);
	return (NULL);
}
