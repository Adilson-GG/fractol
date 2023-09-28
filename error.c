/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:41:23 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:10:35 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	msg_error(int num, t_data *ptr)
{
	if (num == 1)
		ft_printf("Fail malloc\n");
	else
		free(ptr);
	if (num == 2)
		ft_printf("Fail initizialisation\n");
	if (num == 3)
	{
		ft_printf("Wrong arguments\n");
		ft_printf("Please try with [Mandelbrot] ");
		ft_printf("or [Julia [cr] [ci]] or [Bonus]\n");
	}
	return (0);
}
