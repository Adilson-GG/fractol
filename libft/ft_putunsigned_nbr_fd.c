/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_nbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:36:59 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/04 13:37:01 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_convunsigned(unsigned int nb, int base)
{
	int		i;

	i = 1;
	if (nb < (unsigned int)base)
		return (1);
	while (nb >= (unsigned int)base)
	{
		nb = nb / (unsigned int)base;
		i ++;
	}
	return (i);
}

void	ft_putunsigned_nbr_fd(unsigned int nb, int fd)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

/*int main()
{
	ft_putnbr_fd(-5505, 0);
	return 0;
}*/