/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:40:19 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 22:40:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fdf.h>

static void		without_argument(t_map **begin_list_maps)
{
	DIR				*rep;
	struct dirent	*map;
	char			*path;

	if ((rep = opendir("./maps/")))
	{
		while ((map = readdir(rep)))
		{
			if (ft_strcmp(map->d_name, ".") != 0 && ft_strcmp\
	(map->d_name, "..") != 0)
			{
				path = ft_strjoin("./maps/", map->d_name);
				if (*begin_list_maps == NULL)
					*begin_list_maps = ft_create_elem(path);
				else
					ft_push_back(begin_list_maps, path);
				free(path);
			}
		}
		closedir(rep);
	}
	else
		*begin_list_maps = ft_create_elem(NULL);
}

static void		with_argument(t_map **begin_list_maps, int argc, char **argv)
{
	int				i;
	struct stat		file;

	i = 1;
	while (i < argc)
	{
		if (stat(argv[i], &file) != -1)
		{
			if (S_IFREG & file.st_mode)
			{
				if (ft_strcmp(argv[i], ".") != 0 &&\
	ft_strcmp(argv[i], "..") != 0)
				{
					if (*begin_list_maps == NULL)
						*begin_list_maps = ft_create_elem(argv[i]);
					else
						ft_push_back(begin_list_maps, argv[i]);
				}
			}
		}
		i++;
	}
}

t_map			*ft_get_maps(int argc, char **argv)
{
	t_map			*begin_list_maps;

	begin_list_maps = NULL;
	if (argc > 1)
		with_argument(&begin_list_maps, argc, argv);
	else
		without_argument(&begin_list_maps);
	return (begin_list_maps);
}
