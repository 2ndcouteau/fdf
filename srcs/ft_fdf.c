/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:59:17 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 21:40:57 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

int			expose_hook(t_env *e)
{
	draw_grille(e);
	return (0);
}

static void	ft_print_fdf(t_map *begin_list)
{
	t_env	e;

	e.win_w = 1900;
	e.win_h = 1900;
	e.decal_x = 0;
	e.decal_y = 0;
	e.b_len = 2;
	e.ez = 1;
	e.fact = 1;
	e.map = begin_list;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.win_w, e.win_h, "42 EZLIFE");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}

void		ft_fdf(t_map **begin_list)
{
	ft_print_fdf(*begin_list);
}
