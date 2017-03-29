/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_param_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 22:49:53 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 22:32:39 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static int		ft_len_elem(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ' && line[i] != '\0')
		{
			if (line[i] == '-' || ft_isdigit(line[i]))
			{
				if (i > 0 && line[i - 1] != ' ' && line[i] == '-')
					return (-1);
				i++;
			}
			else
				return (-1);
		}
		if (ft_isdigit((int)line[i - 1]))
			nb++;
	}
	return (nb);
}

static int		get_next_action(t_map **begin_list, char *line, int fd)
{
	while (get_next_line(fd, &line) > 0)
	{
		if ((*begin_list)->i == 0)
			(*begin_list)->w = ft_len_elem(line);
		if ((*begin_list)->w != ft_len_elem(line) ||\
	(*begin_list)->w == -1)
		{
			(*begin_list)->error = 2;
			return (1);
		}
		(*begin_list)->i++;
		free(line);
	}
	close(fd);
	if ((*begin_list)->w == -1)
	{
		(*begin_list)->error = 2;
		return (1);
	}
	return (0);
}

bool			recup_param_map(t_map **begin_list, char *line, int fd)
{
	(*begin_list)->i = 0;
	(*begin_list)->w = -1;
	if ((fd = open((*begin_list)->path, O_RDWR)) != -1)
	{
		if (get_next_action(begin_list, line, fd) == 1)
			return (1);
	}
	(*begin_list)->h = (*begin_list)->i;
	return (0);
}
