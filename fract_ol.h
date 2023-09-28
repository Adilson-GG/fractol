/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:54:56 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:28:33 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "math.h"
# include "libft/libft.h"

typedef struct s_data
{
	int				x;
	int				y;
	int				hgt;
	int				wdt;
	int				zoom;
	int				size;
	int				fract;
	int				mv_x;
	int				mv_y;
	void			*mlx_ptr;
	void			*win_ptr;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	unsigned int	shift_x;
	unsigned int	shift_y;
	unsigned int	shift_z;
}	t_data;

typedef struct s_imge
{
	void	*img_ptr;
	char	*data;
	int		size_line;
	int		bits_per_pixel;
	int		endi;
}	t_imge;

int		parsing(int argc, char **argv, t_data *ptr);
void	draw(t_data *ptr, int i, t_imge *img);
void	algo(t_data *ptr);
void	algo_mandel(t_data *ptr, t_imge *img);
void	algo_julia(t_data *ptr, t_imge *img);
void	algo_sierpinski(t_data *ptr, t_imge *img);
int		init_data(t_data *ptr);
int		init_img(t_imge *img, t_data *ptr);
void	shift_color(t_data *ptr);
int		msg_error(int num, t_data *ptr);

#endif