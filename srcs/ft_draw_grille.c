/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_grille.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 20:17:22 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/30 13:27:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void		h_is_good(t_env *e, int h, int w)
{
	e->start_x = (e->win_w / 3) - ((e->b_len * e->ez) * h) - e->decal_x;
	e->start_y = (e->win_h / 10) + ((e->b_len * e->ez) * h) - e->decal_y;
	if (e->map->map[h][w + 1] > 0 || e->map->map[h][w] > 0)
		e->color = M_RED;
	else
		e->color = M_BLUE;
	e->y1 = e->start_y + (w * (e->b_len * e->ez)) -\
	(e->map->map[h][w] * e->fact);
	e->y2 = e->start_y + (w * (e->b_len * e->ez)) + (e->b_len * e->ez) -\
	(e->map->map[h][w + 1] * e->fact);
	e->x1 = e->start_x + (w * (e->b_len * e->ez));
	e->x2 = e->start_x + (w * (e->b_len * e->ez)) + (e->b_len * e->ez);
}

static void		h_in_boucle(t_env *e, int h, int w)
{
	if (e->map->map[h + 1][w] > 0 || e->map->map[h][w] > 0)
		e->color = M_RED;
	else
		e->color = M_BLUE;
	e->y1 = e->start_y + (w * (e->b_len * e->ez)) -\
	(e->map->map[h][w] * e->fact);
	e->y2 = e->start_y + (w * (e->b_len * e->ez)) + (e->b_len * e->ez) -\
	(e->map->map[h + 1][w] * e->fact);
	draw_segment(e);
}

static void		boucle_w(t_env *e, int h, int w)
{
	while (w < e->map->w)
	{
		if (w < e->map->w - 1)
			draw_segment(e);
		e->x1 = e->start_x + (w * (e->b_len * e->ez));
		e->x2 = e->start_x + (w * (e->b_len * e->ez)) - (e->b_len * e->ez);
		if (h < e->map->h - 1)
			h_in_boucle(e, h, w);
		w++;
		e->x1 = e->start_x + (w * (e->b_len * e->ez));
		e->x2 = e->start_x + (w * (e->b_len * e->ez)) + (e->b_len * e->ez);
		if (w < e->map->w - 1)
		{
			if (e->map->map[h][w + 1] > 0 || e->map->map[h][w] > 0)
				e->color = M_RED;
			else
				e->color = M_BLUE;
			e->y1 = e->start_y + (w * (e->b_len * e->ez)) -\
	(e->map->map[h][w] * e->fact);
			e->y2 = e->start_y + (w * (e->b_len * e->ez)) +\
	(e->b_len * e->ez) - (e->map->map[h][w + 1] * e->fact);
		}
	}
}

static void		boucle_draw(t_env *e, int h, int w)
{
	while (h < e->map->h)
	{
		boucle_w(e, h, w);
		w = 0;
		h++;
		if (h < e->map->h)
			h_is_good(e, h, w);
	}
}

void			draw_grille(t_env *e)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx_clear_window(e->mlx, e->win);
	e->start_x = (e->win_w / 3) - e->decal_x;
	e->start_y = (e->win_h / 10) - e->decal_y;
	e->y1 = e->start_y + (h * (e->b_len * e->ez)) -\
	(e->map->map[h][w] * e->fact);
	e->y2 = e->start_y + (h * (e->b_len * e->ez)) +\
	(e->b_len * e->ez) - (e->map->map[h][w + 1] * e->fact);
	e->x1 = e->start_x + (w * (e->b_len * e->ez));
	e->x2 = e->start_x + (w * (e->b_len * e->ez)) + (e->b_len * e->ez);
	if (e->map->map[h][w + 1] > 0 || e->map->map[h][w] > 0)
		e->color = M_RED;
	else
		e->color = M_BLUE;
	boucle_draw(e, h, w);
}
