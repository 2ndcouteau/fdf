/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_one_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:08:39 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 23:03:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void		ft_init_tab(t_map **begin_list)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (((*begin_list)->map = malloc(sizeof(int*) * (*begin_list)->h)))
	{
		while (i < (*begin_list)->h)
		{
			if (((*begin_list)->map[i] = malloc(sizeof(int) *\
	(*begin_list)->w)))
			{
				while (a < (*begin_list)->w)
				{
					(*begin_list)->map[i][a] = 0;
					a++;
				}
			}
			a = 0;
			i++;
		}
	}
}

static void		ft_split_line(char *line, t_map **begin_list, int c)
{
	int		cpt;
	int		a;
	int		d;

	a = 0;
	d = 0;
	cpt = 0;
	while (line[cpt] != '\0')
	{
		while (line[cpt] && (line[cpt] != '-' && !(ft_isdigit(line[cpt]))))
			cpt++;
		while (line[cpt + d] && (line[cpt + d] == '-' ||\
	ft_isdigit(line[cpt + d])))
			d++;
		(*begin_list)->map[c][a] = ft_atoi(&line[cpt]);
		cpt = cpt + d;
		d = 0;
		a++;
	}
}

bool			ft_get_one_map(t_map **begin_list)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	line = NULL;
	if (recup_param_map(begin_list, line, fd))
		return (1);
	ft_init_tab(begin_list);
	if ((fd = open((*begin_list)->path, O_RDWR)) != -1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_split_line(line, begin_list, i);
			i++;
			free(line);
		}
	}
	return (0);
}
