/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:20:59 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:58:25 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Duplicates `str` onto a new heap allocated buffer.
/// This function allocates maximum of ft_strlen(str) + 1 onto
/// the heap.
/// RETURN(s):
/// `NULL` - on failure to allocate memory
/// `char *` - on success
char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	buf_sz;

	buf_sz = ft_strlen(str) + 1;
	ptr = malloc(buf_sz);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, buf_sz);
	return (ptr);
}
