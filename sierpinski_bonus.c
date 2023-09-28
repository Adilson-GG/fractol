/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 07:40:59 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/28 08:28:07 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// void draw_sierpinski(int x, int y, int size) {
//     if (size == 1) {
//         printf("#");
//     } else {
//         int subSize = size / 3;
//         int isBlank = (x / subSize) % 3 == 1 && (y / subSize) % 3 == 1;

//         if (isBlank) {
//             printf(" ");
//         } else {
//             draw_sierpinski(x, y, subSize);
//         }
//     }
// }

// int main() {
//     int size = 27;
//     for (int y = 0; y < size; y++) {
//         for (int x = 0; x < size; x++) {
//             draw_sierpinski(x, y, size);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// void	algo_sierpinski(int x, int y, t_data *ptr, t_imge *img)
// {
// 	if (ptr->size == 1)
// 	{	
// 		printf("d\n");
// 		draw(x, y, ptr, 120, img);
// 	}
//     else
// 	{
// 		printf("x = %d\n", x);
//         ptr->size = ptr->size / 3;
//         if ((x / ptr->size) % 3 == 1 && (y / ptr->size) % 3 == 1)
//             draw(x, y, ptr, 0, img);
// 		else
//             algo_sierpinski(x, y, ptr, img);
//     }
// }

void	algo_sierpinski(t_data *ptr, t_imge *img)
{
	int	tx;
	int	ty;
	int	count;

	tx = (ptr->x * ptr->zoom) + ptr->mv_x;
	ty = (ptr->y * ptr->zoom) + ptr->mv_y;
	count = 0;
	while (tx > 0 || ty > 0)
	{
		if (tx % 3 == 1 && ty % 3 == 1)
			count++;
		tx /= 3;
		ty /= 3;
	}
	if (count > 0)
		draw(ptr, 120, img);
	else
		draw(ptr, 0, img);
}
