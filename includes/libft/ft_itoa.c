/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:22:14 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:40:37 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/// Gets the number of 'places' in `num`.
/// E.g:
/// 1003 has 4 'places', this returns 4.
/// 0 has 1 'places', therefore this returns 1.
static size_t	*ft_numc(long num, size_t *count, int is_neg)
{
	if (is_neg || num == 0)
		(*count)++;
	while (num != 0)
	{
		(*count)++;
		num /= 10;
	}
	return (count);
}

/// Converts 'num' into a `char *` .
/// A memory region of size `count + 1` will be allocated, and
/// the return value is guaranteed to be NUL-terminated.
/// count is expected to include '-' sign if present.
static char	*ft_strfnum(long num, size_t count, int is_neg)
{
	char	*str;

	str = malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count != 0)
	{
		str[--count] = (num % 10) + '0';
		if (count == 0 && is_neg)
			str[count] = '-';
		num /= 10;
	}
	return (str);
}

/// Converts `int` to `char *`.
/// RETURN(s):
/// `NULL` - on failure to allocate memory. 
/// `char *` - (number translated to `char *` ) on success.
char	*ft_itoa(int num)
{
	int			is_neg;
	long		lnum;
	size_t		count;

	lnum = num;
	count = 0;
	is_neg = 0;
	if (num < 0)
	{
		is_neg = 1;
		lnum = -lnum;
	}
	ft_numc(lnum, &count, is_neg);
	return (ft_strfnum(lnum, count, is_neg));
}
