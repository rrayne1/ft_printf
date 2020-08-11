/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_douf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:46:46 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 14:46:48 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		type_d(va_list args, t_flags *flag)
{
	intmax_t	nb;
	int			size;

	ft_get_nb(args, &nb, flag);
	size = ft_getsize(nb);
	if (flag->width != 0)
		flag->width -= size;
	if (nb < 0 && (flag->neg = 1) == 1)
	{
		flag->width--;
		flag->total += 1;
	}
	if ((flag->plus || flag->space) && nb >= 0)
		flag->total += 1;
	if (flag->plus && flag->space)
		flag->space = 0;
	if (flag->minus && flag->zero == 0)
		flag->zero = 1;
	if (flag->prec > 0)
		flag->zero = 1;
	ft_display_d(nb, size, flag);
	flag->count += 1;
	return (flag->total);
}

int		type_f(va_list args, t_flags *flag)
{
	t_float		*f;
	int			size;

	if (!(f = (t_float *)malloc(sizeof(t_float))))
		return (0);
	init_float(f);
	f->nb = (flag->type == TYPE_LF ? \
									va_arg(args, long double) :\
									va_arg(args, double));
	size = 1;
	if ((1.0 / f->nb == -1.0 / 0.0 || f->nb < 0) && size--)
	{
		flag->neg = 1;
		f->nb = -f->nb;
	}
	check_size(&size, f, flag);
	if (flag->prec == 0)
		size = (ft_getsize((intmax_t)f->nb));
	ft_full(f, flag);
	free(f);
	flag->total = size;
	flag->count += 1;
	return (flag->total);
}

int		type_o(va_list args, t_flags *flag)
{
	uintmax_t	nb;
	int			size;

	ft_get_nb_u(args, &nb, flag);
	size = 0;
	ft_get_size_u(nb, 8, &size);
	if ((flag->minus && flag->zero == 0) || flag->prec > 0)
		flag->zero = 1;
	if (flag->prec > 0 && nb == 0)
		flag->hash = 0;
	if (flag->hash)
	{
		if (nb != 0)
			size += 1;
		else
			flag->width -= 1;
	}
	flag->width -= size;
	ft_display_o(nb, size, flag);
	if (flag->hash && nb == 0)
		flag->total = 1;
	flag->count += 1;
	return (flag->total);
}

int		type_u(va_list args, t_flags *flag)
{
	uintmax_t	nb;
	int			size;

	ft_get_nb_u(args, &nb, flag);
	size = 0;
	ft_get_size_u((uintmax_t)nb, 10, &size);
	if (flag->width != 0)
		flag->width -= size;
	if ((flag->prec > 0 && flag->width) || \
			(!flag->zero && flag->minus))
		flag->zero = 1;
	ft_display_u(nb, size, flag);
	flag->count += 1;
	return (flag->total);
}
