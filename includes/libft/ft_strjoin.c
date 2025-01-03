/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:35:55 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:22:26 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Creates a new heap-allocated string containing `str1` 
/// and `str2` concatenated.
/// This function allocates maximum of ft_strlen(str1) + ft_strlen(str2) + 1
/// onto the heap.
/// RETURN(s):
///	`NULL` - on failure to allocate memory
///	`char *` - (new `char *` allocated) that on success
char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*ptr;
	size_t	sum_len;

	sum_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	ptr = malloc(sum_len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str1, sum_len);
	ft_strlcat(ptr, str2, sum_len);
	return (ptr);
}
