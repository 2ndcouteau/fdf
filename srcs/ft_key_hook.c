/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 20:42:45 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 23:25:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void	key_next_map(t_env *e)
{
	if (e->map->next != NULL)
	{
		e->map = e->map->next;
		draw_grille(e);
	}
}

static void	key_refresh(t_env *e)
{
	draw_grille(e);
}

static void	key_mult(t_env *e)
{
	if ((e->fact + 1) < 30)
	{
		e->fact++;
		draw_grille(e);
	}
}

static void	key_add(t_env *e)
{
	if (e->b_len * (e->ez + 1) < INT_MAX)
	{
		e->ez++;
		draw_grille(e);
	}
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 15)
		key_refresh(e);
	if (keycode == 45)
		key_next_map(e);
	if (keycode == 67)
		key_mult(e);
	if (keycode == 69)
		key_add(e);
	if (keycode > 70)
		key_sup(keycode, e);
	return (0);
}
