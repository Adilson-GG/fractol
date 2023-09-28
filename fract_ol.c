/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:03:02 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:12:20 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_window(void *param)
{
	t_data	*ptr2;

	ptr2 = (t_data *)param;
	mlx_destroy_window(ptr2->mlx_ptr, ptr2->win_ptr);
	exit(0);
}

int	key_press2(int keycode, t_data *ptr2)
{
	if ((keycode >= 65361 && keycode <= 65364)
		|| keycode == 53 || keycode == 52)
	{
		mlx_clear_window(ptr2->mlx_ptr, ptr2->win_ptr);
		algo(ptr2);
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_data	*ptr2;

	ptr2 = (t_data *)param;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(ptr2->mlx_ptr, ptr2->win_ptr);
		exit(0);
	}
	else if (keycode == 53)
		ptr2->zoom *= 2;
	else if (keycode == 52)
	{
		if (ptr2->zoom > 1)
			ptr2->zoom /= 2;
	}
	else if (keycode == 65362)
		ptr2->mv_y += 19 * ptr2->zoom;
	else if (keycode == 65364)
		ptr2->mv_y -= 19 * ptr2->zoom;
	else if (keycode == 65363)
		ptr2->mv_x -= 19 * ptr2->zoom;
	else if (keycode == 65361)
		ptr2->mv_x += 19 * ptr2->zoom;
	return (key_press2(keycode, ptr2));
}

int	main(int argc, char **argv)
{
	t_data	*ptr;

	ptr = (t_data *)malloc(sizeof(t_data));
	if (!ptr)
		return (msg_error(1, ptr));
	if (!init_data(ptr))
		return (msg_error(2, ptr));
	if (!parsing(argc, argv, ptr))
		return (msg_error(3, ptr));
	algo(ptr);
	mlx_hook(ptr->win_ptr, 17, 0, &close_window, ptr);
	mlx_key_hook(ptr->win_ptr, &key_press, ptr);
	mlx_loop(ptr->mlx_ptr);
	free(ptr);
	return (0);
}
