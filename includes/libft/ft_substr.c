/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:23:13 by ialee             #+#    #+#             */
/*   Updated: 2024/11/11 22:24:26 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		len = 0;
	if (start + len > str_len)
		len = str_len - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &str[start], len + 1);
	return (ptr);
}
