/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_segment_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:42:26 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/28 19:10:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

void	draw_segment_2(t_env *e, int dx, int dy, int d)
{
	if (dx > 0)
		draw_segment_dx_sup(e, dx, dy, d);
	else
	{
		if ((dy = e->y2 - e->y1) != 0)
			draw_segment_dx_inf(e, dx, dy, d);
		else
		{
			while (e->x1 != e->x2)
			{
				mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
				e->x1--;
			}
		}
	}
}
