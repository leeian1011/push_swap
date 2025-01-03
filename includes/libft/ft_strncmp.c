/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:31:43 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:06:21 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Compares up to `len` chars between `str1` and `str2`.
/// RETURN(s):
///	`int` - 0 if no differences were found between `str1` and `str2`.
///	`int` - != 0 if differences were found between `str1` and `str2`.
int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	while (len--)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1++ == '\0')
			return (0);
		str2++;
	}
	return (0);
}
