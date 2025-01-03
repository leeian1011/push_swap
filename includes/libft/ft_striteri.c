/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:41 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 21:44:39 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Iterator over `str` applying `fn` on each char.
/// RETURN(s):
/// Nothing
void	ft_striteri(char *str, void (*fn)(unsigned int, char *))
{
	size_t	index;

	index = 0;
	while (*str)
		fn(index++, str++);
}
