/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 11:44:02 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/09 18:09:24 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define FDF_H

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		**map;
	int		map_size[2];
	int		window_size[2];
	char	**arg;
	int		offset[2];
	int		scale;
	int		z_scale;
}	t_data;

int		parse_map(t_data *tab);
void	render_map(t_data *tab);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_data *data, t_coords *a, t_coords *b);
void	fill(t_data *tab, int width, int height, int color);
void	get_coords(t_data *tab, int x, int y, t_coords *coord);
void	ft_free_tab(char **tab);
void	ft_free_map(t_data	*tab);
int		ft_height(t_data *data);
int		ft_width(t_data *data);
int		key(int keycode, t_data *tab);
int		close_hook(t_data *tab);
int		center_map(t_data *tab);

#endif