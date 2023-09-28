/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:11:23 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/11 08:11:24 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_param3(const char si, va_list ap)
{
	int	nb;

	if (si == 'x' || si == 'X')
	{
		nb = va_arg(ap, unsigned int);
		if (si == 'X')
			ft_putstr_free_fd(ft_unsigned_conv_baseup(nb, 16), 1);
		else
			ft_putstr_free_fd(ft_unsigned_conv_base(nb, 16), 1);
		return (ft_unsigned_longueur(nb, 16));
	}
	else
		return (-1);
}

int	ft_param2(const char si, va_list ap)
{
	int	nb;

	if (si == 'd' || si == 'i')
	{
		nb = va_arg(ap, int);
		ft_putnbr_fd(nb, 1);
		return (ft_longueur(nb, 10));
	}
	else if (si == 'u')
	{
		nb = va_arg(ap, unsigned int);
		ft_putunsigned_nbr_fd(nb, 1);
		return (ft_convunsigned(nb, 10));
	}
	else if (si == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (si == 'p')
		return (ft_putadd(va_arg(ap, void *)));
	else
		return (ft_param3(si, ap));
}

int	ft_param(const char si, va_list ap)
{
	char	c;
	char	*s;

	if (!si)
		return (0);
	else if (si == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar_fd(c, 1);
		return (0);
	}
	else if (si == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			return (ft_casnull());
		ft_putstr_fd(s, 1);
		return (ft_strlen(s) - 1);
	}
	else
		return (ft_param2(si, ap) - 1);
}

int	ft_option(const char *str, va_list ap, int *val)
{
	int	i;
	int	add;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i ++;
		}
		if (str[i] == '%')
		{
			i ++;
			add = ft_param(str[i], ap);
			*val = *val + add;
			i ++;
		}
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		val;
	va_list	ap;

	val = 0;
	va_start(ap, str);
	val += ft_param_len(str);
	ft_option(str, ap, &val);
	va_end(ap);
	return (val);
}

// #include <stdio.h>
// int main()
// {
// 	int a = 9;
// 	printf("%d\n", ft_printf(" % ", &a));
// 	printf("%d\n", printf(" %", &a));
// 	return (0);
// }