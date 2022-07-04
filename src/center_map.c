/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   center_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 11:53:38 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/03 09:30:30 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	center_map(t_data *tab)
{
	t_coords	a;
	t_coords	b;

	while (1)
	{
		get_coords(tab, 0, 0, &a);
		get_coords(tab, tab->width - 1, tab->height - 1, &b);
		tab->offset[0] = (tab->window_size[0] / 2) - (abs(a.x - b.x) / 2);
		tab->offset[1] = (tab->window_size[1] / 2) - (abs(a.y - b.y) / 2);
		if (abs(a.x - b.x) > 1920 || abs(a.y - b.y) > 1080)
		{
			tab->scale--;
			continue ;
		}
		break ;
	}
	return (0);
}
