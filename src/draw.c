/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 11:37:28 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/02 12:04:13 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define LINE_COLOR 0x00FFFFFF

static int	ft_select(int val, int a, int b)
{
	if (val)
		return (a);
	return (b);
}

static void	ft_setup(t_coords *a, t_coords *b, int *delta, int *incr)
{
	delta[0] = abs(a->x - b->x);
	delta[1] = abs(a->y - b->y);
	incr[0] = ft_select(b->x < a->x, 1, -1);
	incr[1] = ft_select(b->y < a->y, 1, -1);
}

void	draw_line(t_data *data, t_coords *a, t_coords *b)
{
	int	delta[2];
	int	incr[2];
	int	cur[2];
	int	err;

	ft_setup(a, b, delta, incr);
	err = 2 * (delta[1] - delta[0]);
	cur[0] = b->x;
	cur[1] = b->y;
	while (1)
	{
		my_mlx_pixel_put(data, cur[0], cur[1], LINE_COLOR);
		if (cur[0] == a->x && cur[1] <= a->y)
			break ;
		if (err >= 0)
		{
			cur[1] += incr[1];
			err -= 2 * delta[0];
		}
		if (err < 0)
		{
			cur[0] += incr[0];
			err += 2 * delta[1];
		}
	}
}
