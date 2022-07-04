/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 14:29:31 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/02 12:40:24 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill(t_data *tab, int width, int height, int color)
{
	int	temp_height;

	while (width > 0)
	{
		width--;
		temp_height = height;
		while (temp_height > 0)
		{
			temp_height--;
			my_mlx_pixel_put(tab, width, temp_height, color);
		}
	}
}

void	get_coords(t_data *tab, int x, int y, t_coords *coord)
{
	coord->x = (x - y) * cos(0.523599) * tab->scale;
	coord->y = (-tab->map[y][x] * tab->z_scale) + (x + y) \
				* sin(0.523599) * tab->scale;
	coord->x += tab->offset[0];
	coord->y += tab->offset[1];
}

static void	draw_x(t_data *tab, int y)
{
	int			i;
	t_coords	p1;
	t_coords	p2;

	i = 0;
	while (i < tab->width - 1)
	{
		get_coords(tab, i, y, &p1);
		get_coords(tab, i + 1, y, &p2);
		draw_line(tab, &p1, &p2);
		i++;
	}
}

static void	draw_y(t_data *tab, int x)
{
	int			i;
	t_coords	p1;
	t_coords	p2;

	i = 0;
	while (i < tab->height - 1)
	{
		get_coords(tab, x, i, &p1);
		get_coords(tab, x, i + 1, &p2);
		draw_line(tab, &p1, &p2);
		i++;
	}
}

void	render_map(t_data *tab)
{
	int	i;

	i = 0;
	while (i < tab->height)
	{
		draw_x(tab, i);
		i++;
	}
	i = 0;
	while (i < tab->width)
	{
		draw_y(tab, i);
		i++;
	}
}
