/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:20:40 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/11 08:20:42 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_longueur(int nb, int base)
{
	int		i;
	long	nbr;

	i = 1;
	nbr = nb;
	if (nb < 0)
	{
		nbr = -nbr;
		i ++;
	}
	if (nbr < base)
		return (i);
	while (nbr >= base)
	{
		nbr = nbr / base;
		i ++;
	}
	return (i);
}

char	*ft_rev_tab(char *dest, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < (len / 2))
	{
		c = dest[i];
		dest[i] = dest[len - 1 - i];
		dest[len - 1 - i] = c;
		i ++;
	}
	return (dest);
}

char	*ft_conv_base(int nb, int base)
{
	char	*s;
	char	*dest;
	int		i;
	int		len;

	s = "0123456789abcdef";
	i = 0;
	len = ft_longueur(nb, base);
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
