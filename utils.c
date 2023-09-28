/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:40:47 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:29:59 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	shift_color(t_data *ptr)
{
	ptr->shift_x = ptr->mv_x + 32;
	ptr->shift_y = ptr->mv_y + 256;
	ptr->shift_z = ptr->zoom * 1000 + 1024;
}

int	init_data(t_data *ptr)
{
	ptr->x = 0;
	ptr->y = 0;
	ptr->hgt = 900;
	ptr->wdt = 900;
	ptr->zoom = 1;
	ptr->zr = 0;
	ptr->zi = 0;
	ptr->mv_x = 0;
	ptr->mv_y = 0;
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		return (0);
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->wdt, ptr->hgt, "fract-ol");
	if (!ptr->win_ptr)
		return (0);
	return (1);
}

int	init_img(t_imge *img, t_data *ptr)
{
	img->bits_per_pixel = 32;
	img->img_ptr = mlx_new_image(ptr->mlx_ptr, ptr->wdt, ptr->hgt);
	if (!img->img_ptr)
		return (msg_error(2, ptr));
	img->size_line = ptr->wdt * (img->bits_per_pixel / 8);
	img->endi = 0;
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel),
			&(img->size_line), &(img->endi));
	if (!img->data)
		return (msg_error(2, ptr));
	return (1);
}

int	create_color(int i)
{
	int	color;

	if (i == 150)
		color = 0x0000FF;
	else if (i >= 140)
		color = 0x800080;
	else if (i >= 100)
		color = 0x008000;
	else if (i >= 80)
		color = 0x808080;
	else if (i >= 50)
		color = 0x1F0808;
	else if (i >= 20)
		color = 0xDF08F8;
	else if (i >= 10)
		color = 16776960;
	else if (i >= 9)
		color = 0x630DE8;
	else
		color = 0;
	return (color);
}

void	draw(t_data *ptr, int i, t_imge *img)
{
	unsigned int	color;
	char			*dst;

	shift_color(ptr);
	color = create_color(i);
	if (abs(ptr->x) > ptr->wdt || abs(ptr->y) > ptr->hgt
		|| ptr->x < 0 || ptr->y < 0)
		return ;
	dst = img->data + ((ptr->y * ptr->wdt + ptr->x)
			* (img->bits_per_pixel / 8));
	if (color)
		*(unsigned int *)dst = color + ptr->shift_x + ptr->shift_y
			+ ptr->shift_z;
	else
		*(unsigned int *)dst = color;
}
