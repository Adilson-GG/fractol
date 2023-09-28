/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:22:10 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/11 14:22:11 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignedlong_longueur(unsigned long nb, int base)
{
	int	i;

	i = 1;
	if (nb < (unsigned long)base)
		return (1);
	while (nb >= (unsigned long)base)
	{
		nb = nb / (unsigned long)base;
		i ++;
	}
	return (i);
}

char	*ft_unsignedlong_conv_base(unsigned long nb, int base)
{
	char	*s;
	char	*dest;
	int		i;
	int		len;

	s = "0123456789abcdef";
	i = 0;
	len = ft_unsignedlong_longueur(nb, base);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (nb == 0)
	{
		dest[i] = s[0];
		i ++;
	}
	while (nb > 0)
	{
		dest[i] = s[nb % base];
		nb = nb / base;
		i ++;
	}
	dest[i] = '\0';
	return (ft_rev_tab(dest, len));
}

int	ft_putadd(void *s)
{
	long long	add;

	add = (long long)s;
	if (add == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_free_fd(ft_unsignedlong_conv_base(add, 16), 1);
	return (ft_unsignedlong_longueur(add, 16) + 2);
}
