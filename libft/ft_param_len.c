/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:01:04 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/12 10:01:06 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_casnull(void)
{
	ft_putstr_fd("(null)", 1);
	return (5);
}

int	ft_param_len(const char *str)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p'
					|| str[i + 1] == 'd' || str[i + 1] == 'i'
					|| str[i + 1] == 'u' || str[i + 1] == 'x'
					|| str[i + 1] == 'X' || str[i + 1] == '%'))
				comp ++;
			if ((str[i + 1]) == '%')
			{
				i ++;
				comp ++;
			}
		}
		else
			comp ++;
		i ++;
	}
	return (comp);
}
