/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 23:19:07 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 22:15:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

void	ft_print_error(int error)
{
	if (error == 1)
		ft_putendl_fd("Can't open directory in argument(s).", 2);
	else if (error == 2)
		ft_putendl_fd("There is a bad map in \"maps/\" or argument(s).", 2);
	else if (error == 3)
		ft_putendl_fd("No maps directory", 2);
}
