/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:37:40 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 22:23:35 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

t_map		*ft_create_elem(char *path)
{
	t_map	*elem;

	if (!(elem = malloc(sizeof(*elem))))
		return (NULL);
	if (path != NULL)
	{
		elem->path = path;
		elem->error = 0;
		ft_get_one_map(&elem);
		elem->next = NULL;
	}
	else
	{
		elem->map = NULL;
		elem->next = NULL;
		elem->error = 3;
	}
	return (elem);
}
