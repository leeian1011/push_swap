/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:58:07 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:51:14 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/// Compares `n` bytes between memory buffers `s1` and `s2` returning
/// 0 if there is no byte-to-byte difference.
/// RETURN(s):
/// `int` - 0 if no difference between `buf1` and `buf2`
/// `int` - != 0 if there is a difference between `buf1` and `buf2` 
int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	if (n == 0)
		return (n);
	sa = buf1;
	sb = buf2;
	while (n-- > 0)
		if (*sa++ != *sb++)
			return (*--sa - *--sb);
	return (0);
}
