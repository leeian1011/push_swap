/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:38:51 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:56:15 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Concatenates `src` to the end of `dest`.
/// `len` is the full size of `dest` and should include space for '\0'.
/// RETURN(s):
///	`size_t` - size of the string the function attempted to create. 
size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	dest_len;
	size_t	cpy_count;

	dest_len = ft_strlen(dest);
	if (dest_len >= len)
		return (len + ft_strlen(src));
	cpy_count = len - dest_len;
	ft_strlcpy(&dest[dest_len], src, cpy_count);
	return (dest_len + ft_strlen(src));
}
