/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 10:23:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/09 13:07:39 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= data->window_size[0] || x < 0)
		return ;
	if (y >= data->window_size[1] || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_data		img;

	if (argc != 2)
		exit(-1);
	img.window_size[0] = 1920;
	img.window_size[1] = 1080;
	img.arg = argv;
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, img.window_size[0], \
								img.window_size[1], "Kut ding");
	img.img = mlx_new_image(img.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	img.scale = 20;
	img.z_scale = 1;
	fill(&img, img.window_size[0], img.window_size[1], 0x00222222);
	if (!parse_map(&img))
		exit(0);
	center_map(&img);
	render_map(&img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_hook(img.win_ptr, 0x11, 0, close_hook, &img);
	mlx_hook(img.win_ptr, 2, 0, key, &img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
