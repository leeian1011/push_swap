/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:26:09 by ialee             #+#    #+#             */
/*   Updated: 2024/11/12 22:20:14 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	unsigned int	rnum;

	rnum = num;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		rnum = -rnum;
	}
	if (rnum > 9)
		ft_putnbr_fd(rnum / 10, fd);
	ft_putchar_fd((rnum % 10) + '0', fd);
}
