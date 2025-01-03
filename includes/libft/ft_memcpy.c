/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:47 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:14:19 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Copies `n` bytes from `buf2` into `buf1` 'byte by byte'.
/// NOTE: This has undefined behaviour if buf1 and buf2 overlaps.
/// RETURN(s):
/// `void *` - (memory address of the first byte of `buf1` ) on success.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
