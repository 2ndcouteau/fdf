/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/25 18:07:28 by qrosa             #+#    #+#             */
/*   Updated: 2015/05/29 22:31:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** ----- System Libs -----
*/
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <mlx.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>

/*
** ----- Color Terminal-----
*/
# define C_RED		"\033[31m"
# define C_BLUE		"\033[1;34m"
# define C_CYAN		"\033[0;36m"
# define C_ORANGE	"\033[0;33m"
# define C_GREEN	"\033[1;32m"
# define C_NONE		"\033[0m"

/*
** ----- Color MLX-----
*/
# define M_RED		0xFF0000
# define M_GREEN	0x00FF00
# define M_BLUE		0x0000FF

/*
** ----- Structure -----
*/
typedef struct		s_map
{
	char			error;
	char			*path;
	int				h;
	int				w;
	int				**map;
	int				i;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				win_w;
	int				b_len;
	int				ez;
	int				fact;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				start_x;
	int				start_y;
	int				decal_x;
	int				decal_y;
	int				color;
	t_map			*map;
}					t_env;

/*
** ----- Main Fonctions -----
*/
int					main(int argc, char **argv);
void				ft_fdf(t_map **begin_list);
t_map				*ft_get_maps(int argc, char **argv);

/*
** ----- Draw Fonctions -----
*/
void				draw_grille(t_env *e);
void				draw_segment(t_env *e);
void				draw_segment_2(t_env *e, int dx, int dy, int d);
void				draw_segment_dx_sup(t_env *e, int dx, int dy, int d);
void				draw_segment_dx_inf(t_env *e, int dx, int dy, int d);

/*
** ----- Check Map Fonctions -----
*/
bool				ft_get_one_map(t_map **begin_list);
t_map				*ft_create_elem(char *path);
void				ft_push_back(t_map **begin_list_maps, char *path);
bool				recup_param_map(t_map **begin_list, char *line, int fd);

/*
** ----- MLX Fonctions -----
*/
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				key_sup(int keycode, t_env *e);

/*
** ----- Print fonctions -----
*/
void				ft_print_error(int error);

#endif
