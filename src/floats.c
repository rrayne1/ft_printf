/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:42:47 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 14:42:51 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_prec(t_float *f, long double nb, t_flags *flag)
{
	long double		tmp;
	int				tprec;
	int				tsize;

	if (flag->prec == 0 || (flag->prec == 1 && !f->type))
		f->size = 1;
	tprec = flag->prec;
	tsize = 0;
	while (tprec-- + 1)
	{
		tmp = (intmax_t)(nb * 10);
		nb = nb * 10;
		if ((int)tmp == 0 || (int)tmp % 10 == 0)
			tsize++;
	}

	if ((f->size = ft_getsize((intmax_t)tmp)) > 1)
	{
		while ((intmax_t)(tmp / 10) % 10 == 0 && (intmax_t)tmp % 10 == 0)
			tmp /= 10;
		f->size = ft_getsize((intmax_t)tmp);
	}
	if (f->type == LDEC && tsize > f->size)
		f->add = 1;
	f->size += tsize;
}

void		ft_get_fal(t_float *f, long double nb, t_flags *flag)
{
	int i;

	nb *= 10;
	f->first = (int)nb;
	i = (int)f->size - 1;
	while (i-- > 0)
		nb *= 10;
	if ((intmax_t)nb % 10 == 9)
	{
		f->last = (intmax_t)nb % 10;
		while ((intmax_t)nb % 10 == 9 && (intmax_t)nb != 0)
			nb /= 10;
		if (f->type == LDEC)
			f->first = (intmax_t)(nb * 10);
		if ((intmax_t)nb % 10 == 0)
		{
			if ((((intmax_t)(nb / 10) % 10) % 2) == 0 && \
					((intmax_t)(nb / 10) % 10) != 0)
				f->first = ((intmax_t)nb / 10) % 10;
		}
		else
			f->first = (intmax_t)nb % 10;
	}
	else if (((intmax_t)nb % 10) == 5)
	{
		f->last = (intmax_t)nb % 10;
		if (f->type > 0)
		{
			if (f->size > 1)
				f->first = (intmax_t)(nb / 10) % 10;
			if (f->size > flag->prec)
				f->first = f->last;
		}
	}
	if (f->last == 0)
	{
		f->last = (intmax_t)nb % 10;
		if (f->first == 9 && f->last == 8 && !f->type)
			f->first = (intmax_t)(nb / 10) % 10;
		if (f->type == LDEC)
		{
			nb /= 10;
			f->last = (intmax_t) nb % 10;
			f->first = (intmax_t) (nb / 10) % 10;
		}
	}
}

int			ldec(t_float *f)
{
	if (f->first == 8 || f->last == 8)
		return (1);
	if (!f->first)
		return (0);
	if (f->first == f->last)
		return (f->first >= 5 ? 1 : 0);
	if (f->last > 5)
		return (1);
	if (f->last < 5)
		return (0);
	return (0);
}

int			dec(t_float *f)
{
	int		feven;

	if ((f->first % 2) == 0)
		feven = 1;
	if (!f->last)
		return (0);
	if (f->first == f->last)
		return (f->first >= 5 && f->size > 1 ? 1 : 0);
	if (f->last > 5)
		return (1);
	if (f->last == 5)
		return ((feven || f->first == 9) ? 1 : 0);
	if (f->last < 5)
		return (0);
	return (0);
}

int			check_precision(t_float *f, t_flags *flag)
{
	long double		tmp;

	tmp = f->nb;
	tmp -= (int)tmp;
	get_prec(f, tmp, flag);
	ft_get_fal(f, tmp, flag);
	if (!f->type)
	{
		if (flag->prec == 0 && f->first >= 5 && ((int)f->nb % 2) != 0)
			return (1);
		if (f->first <= 5)
			return (0);
		if (f->first == 9 && !f->last)
			return (flag->prec == 0 ? 1 : 0);
		if (f->first == 9)
			return (f->last == 8 || f->last == 9 ? 1 : 0);
		if (f->last == 9)
			return (0);
	}
	else if (f->type == DEC)
		return (dec(f));
	else if (f->type == LDEC)
		return (ldec(f));
	return (0);
}
