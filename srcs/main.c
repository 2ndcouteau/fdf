/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:25:30 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 20:32:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

int		main(int argc, char **argv)
{
	t_map *maps;

	maps = NULL;
	maps = ft_get_maps(argc, argv);
	if (maps != NULL && maps->error == 0)
		ft_fdf(&maps);
	else if (maps != NULL)
		ft_print_error(maps->error);
	else
		ft_print_error(1);
	return (0);
}
