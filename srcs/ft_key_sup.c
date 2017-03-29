/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_sup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 21:02:48 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 21:53:17 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void	right_down(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		if ((e->decal_x + 50) < INT_MAX)
		{
			e->decal_x += 50;
			draw_grille(e);
		}
	}
	else
	{
		if ((e->decal_x - 50) > INT_MIN)
		{
			e->decal_x -= 50;
			draw_grille(e);
		}
	}
}

static void left_up(int keycode, t_env *e)
{
	if (keycode == 125)
	{
		if ((e->decal_y - 50) > INT_MIN)
		{
			e->decal_y -= 50;
			draw_grille(e);
		}
	}
	else
	{
		if ((e->decal_y + 50) < INT_MAX)
		{
			e->decal_y += 50;
			draw_grille(e);
		}
	}
}

static void div_less(int keycode, t_env *e)
{
	if (keycode == 78)
	{
		if ((e->ez - 1) > 0)
		{
			e->ez--;
			draw_grille(e);
		}
	}
	else
	{
		if ((e->fact - 1) > 0)
		{
			e->fact--;
			draw_grille(e);
		}
	}
}

void		key_sup(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 124)
		right_down(keycode, e);
	if (keycode == 125 || keycode == 126)
		left_up(keycode, e);
	if (keycode == 75 || keycode == 78)
		div_less(keycode, e);
}
