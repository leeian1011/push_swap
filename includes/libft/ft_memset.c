/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:54:55 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:48:53 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Assigns `c` into `len` bytes of the memory buffer `buf`.
/// RETURN(s):
/// `void *` - (memory address of the first byte of `buf` ) on success.
void	*ft_memset(void *buf, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = buf;
	while (len--)
		*ptr++ = c;
	return (buf);
}
