/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:30:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/09 18:13:50 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_map(t_data	*tab)
{
	int	i;

	i = 0;
	while (i < tab->height)
	{
		free(tab->map[i]);
		i++;
	}
	free(tab->map);
}
