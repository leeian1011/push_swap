/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:02:47 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:21:58 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Searches at most `len` indexes of `str1`, for `str2` within `str1`
/// RETURN(s):
/// `NULL` - if `str2` cannot be found within `str1`.
/// `char *` - (memory address within `str1` of the
/// first occurence of `str2` ) on success.
char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	s2_len;

	s2_len = ft_strlen(str2);
	if (!*str2 || s2_len <= 0)
		return ((char *)str1);
	while (len--)
	{
		if (ft_strncmp(str1++, str2, s2_len) == 0)
			return ((char *)--str1);
		if (len < s2_len)
			return (NULL);
	}
	return (NULL);
}
