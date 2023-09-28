/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_conv_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:45:28 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/11 11:45:31 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_unsigned_longueur(unsigned int nb, int base)
{
	int	i;

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

char	*ft_unsigned_conv_base(unsigned int nb, int base)
{
	char	*s;
	char	*dest;
	int		i;
	int		len;

	s = "0123456789abcdef";
	i = 0;
	len = ft_unsigned_longueur(nb, base);
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

char	*ft_unsigned_conv_baseup(unsigned int nb, int base)
{
	char	*s;
	char	*dest;
	int		i;
	int		len;

	s = "0123456789ABCDEF";
	i = 0;
	len = ft_unsigned_longueur(nb, base);
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
