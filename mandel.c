/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:41:07 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:31:12 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	algo_mandel(t_data *ptr, t_imge *img)
{
	int		i;
	double	tmp;
	double	cr;
	double	ci;

	i = 0;
	ptr->zi = 0;
	ptr->zr = 0;
	cr = ((ptr->x - ptr->wdt / 2 + ptr->mv_x) / (270.0 * ptr->zoom))
		* (2.7 - (-2.1)) + (-2.1);
	ci = ((ptr->y - ptr->hgt / 2 + ptr->mv_y) / (240.0 * ptr->zoom))
		* (2.4 - (-1.2)) + (-1.2);
	while ((ptr->zr * ptr->zr + ptr->zi * ptr->zi) < 4 && i < 50)
	{
		tmp = ptr->zr;
		ptr->zr = ptr->zr * ptr->zr - ptr->zi * ptr->zi + cr;
		ptr->zi = 2 * ptr->zi * tmp + ci;
		i ++;
	}
	draw(ptr, i, img);
}

void	algo_choice(t_data *ptr, t_imge *img)
{
	if (ptr->fract == 1)
		algo_mandel(ptr, img);
	if (ptr->fract == 2)
		algo_julia(ptr, img);
	if (ptr->fract == 3)
		algo_sierpinski(ptr, img);
}

void	manage_window(t_data *ptr, t_imge *img)
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, img->img_ptr, 0, 0);
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 100, 100, 0xFFFFFF,
		"Zoom : 5 / Dezoom : 4 / Depalcements avec les fleches");
	mlx_destroy_image(ptr->mlx_ptr, img->img_ptr);
}

void	algo(t_data *ptr)
{
	t_imge	*img;

	img = (t_imge *)malloc(sizeof(t_imge));
	if (!img)
		return ;
	if (!init_img(img, ptr))
	{
		free(img);
		return ;
	}
	ptr->x = 0;
	while (ptr->x <= (ptr->wdt))
	{
		ptr->y = 0;
		while (ptr->y <= (ptr->hgt))
		{
			algo_choice(ptr, img);
			ptr->y ++;
		}
		ptr->x ++;
	}
	manage_window(ptr, img);
}
