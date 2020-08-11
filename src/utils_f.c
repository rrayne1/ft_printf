/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <rrayne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:59:38 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 15:32:53 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_float(t_float *f)
{
	f->size = 0;
	f->type = 0;
	f->last = 0;
	f->first = 0;
	f->mod = 0;
	f->add = 0;
}

void		check_size(int *size, t_float *f, t_flags *flag)
{
	long double	tmp;

	tmp = f->nb;
	if (flag->prec == -1)
		flag->prec = 6;
	if (flag->prec >= 0)
	{
		tmp += check_precision(f, flag);
		if ((int)tmp > (int)f->nb)
			f->nb += 1;
		f->type = (flag->type == TYPE_LF ? LDEC : DEC);
	}
	*size = *size > flag->width ? *size : flag->width;
	*size += flag->prec;
	if (f->nb < 0 && (flag->neg = 1) == 1)
		*size += 1;
}

int			ft_infinity(char **s, t_float *f)
{
	if (!(*s = ft_strnew((f->nb == 1.0 / 0.0 ? 4 : 5))))
		return (0);
	if (f->nb == 1.0 / 0.0)
		*s = "inf";
	if (f->nb == -1.0 / 0.0)
		*s = "-inf";
	return (ft_strlen(*s));
}

double		ft_modulo(long double nb, int *size)
{
	double modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	(*size)++;
	return (modulo);
}
