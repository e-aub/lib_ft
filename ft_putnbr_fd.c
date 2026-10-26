/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouel-h <ayouel-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:11:53 by ayouel-h          #+#    #+#             */
/*   Updated: 2026/10/26 12:13:20 by ayouel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	ft_putlong_fd(long l_n, int fd)
{
	char	c;

	if (l_n < 0)
	{
		write(fd, "-", 1);
		l_n = -l_n;
	}
	if (l_n >= 0 && l_n <= 9)
	{
		c = l_n + 48;
		write(fd, &c, 1);
	}
	else
	{
		ft_putlong_fd(l_n / 10, fd);
		c = (l_n % 10) + 48;
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
	{
		return ;
	}
	ft_putlong_fd(n, fd);
}
