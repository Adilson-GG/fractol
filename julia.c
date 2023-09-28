/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:41:13 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:27:08 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	algo_julia(t_data *ptr, t_imge *img)
{
	int		i;
	double	tmp;

	i = 0;
	ptr->zi = ((ptr->y - ptr->hgt / 2 + ptr->mv_y) / (400.0 * ptr->zoom))
		* (2.4 - (-1.2)) + (-1.2);
	ptr->zr = ((ptr->x - ptr->wdt / 2 + ptr->mv_x) / (400.0 * ptr->zoom))
		* 4.0 + (-2.0);
	while ((ptr->zr * ptr->zr + ptr->zi * ptr->zi) < 4 && i < 150)
	{
		tmp = ptr->zr;
		ptr->zr = ptr->zr * ptr->zr - ptr->zi * ptr->zi + ptr->cr;
		ptr->zi = 2 * ptr->zi * tmp + ptr->ci;
		i ++;
	}
	draw(ptr, i, img);
}
