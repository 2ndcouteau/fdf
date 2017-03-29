/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_grille.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 12:49:04 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/28 19:12:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void dx_0(t_env *e, int dx, int dy, int d)
{
	if ((dy = e->y2 - e->y1) != 0)
	{
		if (dy > 0)
		{
			while (e->y1 != e->y2)
			{
				mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
				e->y1++;
			}
		}
		else
		{
			while (e->y1 != e->y2)
			{
				mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
				e->y1--;
			}
		}
	}
}

void		draw_segment(t_env *e)
{
	int dx;
	int dy;
	int d;

	if ((dx = e->x2 - e->x1) != 0)
		draw_segment_2(e, dx, dy, d);
	else
		dx_0(e, dx, dy, d);
	mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
}
