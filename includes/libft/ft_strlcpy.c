/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:08:01 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:57:49 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Copies up to 'n' characters from 'src' to 'dest'.
/// If n = 0, no copies will occur.
/// RETURN(s):
///	`size_t` - length of src. 
size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	int	src_len;

	src_len = ft_strlen(src);
	if (len == 0)
		return (src_len);
	while (--len > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (src_len);
}
