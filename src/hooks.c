/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 15:14:06 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/11 09:58:52 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_hook(t_data *tab)
{
	ft_free_map(tab);
	exit(0);
	return (0);
}

static void	zoom(t_data *tab, int keycode)
{
	if (keycode == 40)
		tab->scale += 1;
	else if (keycode == 37)
	{
		tab->scale -= 1;
		if (tab->scale < 1)
			tab->scale += 1;
	}
}

static int	key_hook(t_data *tab, int keycode)
{
	if (keycode == 123)
		tab->offset[0] += 10;
	else if (keycode == 124)
		tab->offset[0] -= 10;
	else if (keycode == 126)
		tab->offset[1] += 10;
	else if (keycode == 125)
		tab->offset[1] -= 10;
	else if (keycode == 31)
		tab->z_scale += 1;
	else if (keycode == 35)
		tab->z_scale -= 1;
	else if (keycode == 53)
	{
		mlx_destroy_window(tab->mlx_ptr, tab->win_ptr);
		ft_free_map(tab);
		exit(0);
	}
	zoom(tab, keycode);
	return (0);
}

int	key(int keycode, t_data *tab)
{
	key_hook(tab, keycode);
	fill(tab, tab->window_size[0], tab->window_size[1], 0x00222222);
	render_map(tab);
	mlx_put_image_to_window(tab->mlx_ptr, tab->win_ptr, tab->img, 0, 0);
	return (0);
}
