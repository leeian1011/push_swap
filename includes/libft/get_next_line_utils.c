/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:48:06 by ialee             #+#    #+#             */
/*   Updated: 2024/11/19 13:26:59 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtonl(char *str)
{
	char	*result;
	size_t	len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
		result[len] = str[len];
	return (result);
}

char	*ft_strchrnl(char *str)
{
	if (!*str)
		return (NULL);
	while (*str)
		if (*str++ == '\n')
			return (--str);
	return (NULL);
}
