/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:56:22 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/12 16:57:55 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_full(t_float *f, t_flags *flag)
{
	char		*bf;
	char		*af;
	char		*s;
	intmax_t	tmp;

	if (!(ft_infinity(&s, f)))
	{
		tmp = (intmax_t)f->nb;
		bf = ft_ditoa(tmp);
		f->nb -= tmp;
		if (flag->prec > 0)
		{
			if (!(af = ft_strnew(flag->prec + 1)))
				return (0);
			ft_full_after(&af, flag, f);
		}
		else
			af = 0;
		if (!(s = ft_strjoin_free(bf, af)))
			return (0);
	}
	ft_display_f(s, flag);
	free(s);
	return (flag->total);
}

void		ft_check_str(char **str, int add)
{
	int		i;
	int		nb;
	char	*s;
	int		mod;

	s = *str;
	i = (int)ft_strlen(&(**str)) - 1;
	if (add == 1)
	{
		while (s[i] == '9')
		{
			s[i] = '0';
			i--;
		}
		if (s[i] != '.')
		{
			nb = ft_atoi(&(s[i]));
			mod = (int)ft_modulo(nb, &add);
			nb = (nb / mod) + 1;
			s[i] = (char)(nb + '0');
		}
	}
}

void		ft_full_after(char **af, t_flags *flag, t_float *f)
{
	int j;
	int tmp;
	int i;
	int add;

	i = 0;
	if (f->nb < 0)
		f->nb = -f->nb;
	if (flag->prec > 0 && (flag->hash = 0) == 0)
		(*af)[i++] = '.';
	flag->total += 1;
	j = 0;
	flag->type = 7;
	add = check_precision(f, flag);
	while (j++ < flag->prec)
	{
		tmp = (intmax_t)(f->nb * 10);
		(*af)[i++] = (char)(tmp + '0');
		f->nb = f->nb * 10 - tmp;
	}
	ft_check_str(af, add);
}

void		check_flags_f(t_flags *flag)
{
	if (flag->hash && flag->prec == 0)
		flag->width--;
	if (flag->plus || flag->space || flag->neg)
		flag->width--;
	if (flag->zero)
		flag->prec = 0;
	if (!flag->neg && flag->plus && flag->space)
		flag->space = 0;
	if (flag->minus)
		flag->zero = 0;
	if (flag->neg)
		flag->total += 1;
}

void		ft_display_f(char *nb, t_flags *flag)
{
	flag->width -= ft_strlen(nb);
	check_flags_f(flag);
	if (flag->zero)
		ft_print_sign(flag);
	if (!flag->minus)
		ft_print_width(flag);
	if (!flag->zero)
		ft_print_sign(flag);
	if (flag->width > 0)
		flag->total -= flag->width;
	ft_write(nb, ft_strlen(nb));
	if (flag->hash && flag->prec == 0)
		ft_write(".", 1);
	if (flag->minus && flag->width > 0)
		ft_print_width(flag);
}
