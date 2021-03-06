/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:41:46 by rrayne            #+#    #+#             */
/*   Updated: 2019/09/27 15:28:06 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	unsigned char	*point;
	size_t			i;

	i = 0;
	point = (unsigned char *)s;
	while (i < n)
	{
		point[i] = 0;
		i++;
	}
}
