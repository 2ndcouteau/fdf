/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_segment_dx_sup.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 18:00:08 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/28 18:51:17 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void	dy_sup_2(t_env *e, int dx, int dy, int d)
{
	d = dy;
	dy = dy * 2;
	dx = dx * 2;
	while (e->y1 != e->y2)
	{
		mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
		e->y1++;
		if ((d -= dx) < 0)
		{
			e->x1++;
			d += dy;
		}
	}
}

static void	dy_sup(t_env *e, int dx, int dy, int d)
{
	if (dx >= dy)
	{
		d = dx;
		dx = dx * 2;
		dy = dy * 2;
		while (e->x1 != e->x2)
		{
			mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
			e->x1++;
			if ((d -= dy) < 0)
			{
				e->y1++;
				d += dx;
			}
		}
	}
	else
		dy_sup_2(e, dx, dy, d);
}

static void	dy_inf_2(t_env *e, int dx, int dy, int d)
{
	d = dy;
	dy = dy * 2;
	dx = dx * 2;
	while (e->y1 != e->y2)
	{
		mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
		e->y1--;
		if ((d += dx) > 0)
		{
			e->x1++;
			d += dy;
		}
	}
}

static void dy_inf(t_env *e, int dx, int dy, int d)
{
	if (dx >= -dy)
	{
		d = dx;
		dx = dx * 2;
		dy = dy * 2;
		while (e->x1 != e->x2)
		{
			mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
			e->x1++;
			if ((d += dy) < 0)
			{
				e->y1--;
				d += dx;
			}
		}
	}
	else
		dy_inf_2(e, dx, dy, d);
}

void		draw_segment_dx_sup(t_env *e, int dx, int dy, int d)
{
	if ((dy = e->y2 - e->y1) != 0)
	{
		if (dy > 0)
			dy_sup(e, dx, dy, d);
		else
			dy_inf(e, dx, dy, d);
	}
	else
	{
		while (e->x1 != e->x2)
		{
			mlx_pixel_put(e->mlx, e->win, e->x1, e->y1, e->color);
			e->x1++;
		}
	}
}
