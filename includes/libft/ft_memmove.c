/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:46:58 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:49:18 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Copies `n` bytes from `buf2` into `buf1` 'byte by byte'
/// and handles memory buffer overlaps.
/// RETURN(s):
/// `void *` - (memory address of the first byte of `buf` ) on success.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dest);
	d = dest;
	s = src;
	if (dest > src)
		while (n-- > 0)
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (dest);
}
