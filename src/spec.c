/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:46:05 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 14:46:08 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_precision(t_flags *flag, int size)
{
	if (flag->prec > 0)
		flag->prec -= size;
	if (flag->width > 0 && flag->prec > 0)
		flag->width -= flag->prec;
	if (flag->prec > 0)
		flag->total += flag->prec;
}

int		check_zero(uintmax_t nb, int *size, t_flags *flag)
{
	if (nb == 0 && (flag->prec == -2 || flag->prec == 0 || \
			flag->hash))
	{
		if (flag->width > 0 && flag->type != P)
			flag->width += *size;
		*size = 0;
		flag->count = 1;
		return (-1);
	}
	return (0);
}
