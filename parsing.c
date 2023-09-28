/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:41:03 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:14:42 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' || (str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i ++;
		else
			return (0);
	}
	return (1);
}

double	next(char *str, int i, double conv, double s)
{
	int		k;
	int		j;
	double	deci;

	if (str[i] == '.')
	{
		k = 1;
		while (str[i + k] >= 48 && str[i + k] <= 57)
		{
			j = k;
			deci = str[i + k] - '0';
			while (j--)
				deci /= 10;
			conv += deci;
			k ++;
		}
	}
	return (s * conv);
}	

double	atoi_double(char *str)
{
	int		i;
	double	s;
	double	conv;

	i = 0;
	conv = 0;
	s = 1;
	if (str[i] != '-' && !(str[i] >= 48 && str[i] <= 57) && str[i] != '+')
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i ++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		conv = (conv * 10) + (str[i] - '0');
		i ++;
	}
	return (next(str, i, conv, s));
}

int	parsing_julia(char **argv, t_data *ptr)
{
	if (!check(argv[2]) || !check(argv[3]))
		return (0);
	ptr->cr = atoi_double(argv[2]);
	ptr->ci = atoi_double(argv[3]);
	ptr->fract = 2;
	return (1);
}

int	parsing(int argc, char **argv, t_data *ptr)
{
	if (argc >= 2)
	{
		if (!ft_strncmp(argv[1], "Mandelbrot", 11))
		{
			if (argc == 2)
			{
				ptr->fract = 1;
				return (1);
			}
		}
		else if (!ft_strncmp(argv[1], "Julia", 6))
		{
			if (argc == 4)
				return (parsing_julia(argv, ptr));
		}
		else if (!ft_strncmp(argv[1], "Bonus", 6))
		{
			if (argc == 2)
			{
				ptr->fract = 3;
				return (1);
			}
		}
	}
	return (0);
}
