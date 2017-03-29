/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:44:24 by qrosa             #+#    #+#             */
/*   Updated: 2014/11/14 17:55:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*freespace;
	char	*init_space;
	size_t	n;

	n = 0;
	freespace = (void *)malloc(size);
	init_space = (char *)freespace;
	if (init_space != NULL)
	{
		while (n < size)
		{
			init_space[n] = 0;
			n++;
		}
		return (freespace);
	}
	return (NULL);
}
