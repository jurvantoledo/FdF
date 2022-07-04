/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 10:05:21 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/03/11 10:05:22 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Eerst b veranderen naar unsigned character pointer. */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = b;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
	Het veranderd het aantal characters wat gelijk is aan 
	length naar wat je op C hebt gezet.
*/