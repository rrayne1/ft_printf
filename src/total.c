/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <rrayne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:46:20 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 22:56:34 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	total_str(char *s, size_t *len, t_flags *flag)
{
	if (flag->prec > 0 && flag->prec < (int)ft_strlen(s))
		*len = flag->prec;
	else
		*len = ft_strlen(s);
	if (flag->prec == -2 || flag->prec == 0)
		*len = 0;
	if (flag->width > 0)
	{
		flag->width -= *len;
		flag->total = flag->width + *len;
	}
}

void	total_dit(intmax_t nb, int size, t_flags *flag)
{
	if (flag->total < 0)
		flag->total = 0;
	if (flag->width == size && size != 0)
		flag->total += size + ft_getsize((uintmax_t)nb);
	if (flag->width != size && flag->width >= 0)
		flag->total += size + flag->width;
	if (flag->width < 0)
		flag->total += size;
}
