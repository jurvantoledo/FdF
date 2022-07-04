/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 10:05:43 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/04/06 15:07:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_height(t_data *tab)
{
	int		fd;
	char	*str;
	int		lines;

	fd = open(tab->arg[1], O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	lines = 0;
	while (str)
	{
		lines++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	ft_width(t_data *tab)
{
	int		fd;
	char	*str;
	char	**map;
	int		amount;

	fd = open(tab->arg[1], O_RDONLY);
	if (fd < 0)
		exit(-1);
	str = get_next_line(fd);
	map = ft_split(str, ' ');
	if (map == NULL)
		exit(-1);
	amount = 0;
	while (map[amount])
		amount++;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	ft_free_tab(map);
	close(fd);
	return (amount);
}

static void	parse_width(t_data *tab, int i, char **parsed_map)
{
	int	j;

	j = 0;
	while (j < tab->width)
	{
		tab->map[i][j] = ft_atoi(parsed_map[j]);
		free(parsed_map[j]);
		j++;
	}
}

static void	parser(char *str, int **map, t_data *tab, int fd)
{
	char	**parsed_map;
	int		i;

	i = 0;
	while (i < tab->height)
	{
		tab->map[i] = malloc(sizeof(int) * tab->width);
		if (map[i] == 0)
			exit(-1);
		parsed_map = ft_split(str, ' ');
		if (parsed_map == NULL)
			return ;
		parse_width(tab, i, parsed_map);
		free(str);
		free(parsed_map);
		str = get_next_line(fd);
		i++;
	}
}

int	parse_map(t_data *tab)
{
	char	*str;
	int		fd;

	tab->height = ft_height(tab);
	tab->width = ft_width(tab);
	tab->map = malloc(sizeof(int *) * tab->height);
	if (tab->map == 0)
		exit(-1);
	fd = open(tab->arg[1], O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	if (str == NULL)
		return (0);
	parser(str, tab->map, tab, fd);
	close(fd);
	return (1);
}
