/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:11:36 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 23:34:46 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

void		ft_push_back(t_map **begin_list_maps, char *path)
{
	t_map *tmp_list;

	tmp_list = *begin_list_maps;
	while (tmp_list->next != NULL)
		tmp_list = tmp_list->next;
	tmp_list->next = ft_create_elem(path);
	if (tmp_list->next->error != 0)
		(*begin_list_maps)->error = tmp_list->next->error;
}
