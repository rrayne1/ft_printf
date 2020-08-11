/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <rrayne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:46:32 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 22:56:39 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_display_precision(t_flags *flag, char *cont)
{
	if (flag->width == 0 && flag->hash && flag->type != P)
	{
		flag->prec -= 2;
		flag->total += 2;
	}
	if (!flag->minus && flag->width > 0)
	{
		ft_print_width(flag);
		flag->total += flag->width;
		flag->width = 0;
	}
	if (flag->hash)
	{
		ft_write(cont, 2);
		flag->hash = 0;
	}
	while (--flag->prec >= 0)
		ft_write("0", 1);
}

void	ft_display_width(t_flags *flag, char *cont)
{
	if (!flag->minus && !flag->hash && !flag->zero)
		ft_print_width(flag);
	if (!flag->minus && flag->zero)
		ft_print_width(flag);
	if (flag->hash)
		ft_write(cont, 2);
	if (!flag->minus && (flag->hash || flag->prec < -1) && !flag->zero)
		ft_print_width(flag);
}

void	ft_display_x(uintmax_t nb, int *size, t_flags *flag, char *base)
{
	char	*cont;
	int		width;

	width = 0;
	cont = ft_strchr(base, 'a') ? "0x" : "0X";
	if (flag->prec > 0)
		flag->zero = 1;
	check_zero(nb, size, flag);
	ft_precision(flag, *size);
	if (flag->prec > 0)
		ft_display_precision(flag, cont);
	if (flag->prec <= 0)
		ft_display_width(flag, cont);
	if (*size > 0 && flag->count != 1)
		ft_putnbr_base((uintmax_t)nb, base, 16);
	if (nb == 0 && (flag->prec == -1) && flag->type == P)
	{
		ft_write("0", 1);
		flag->total += 1;
	}
	while (++width <= flag->width && flag->minus)
		ft_write(" ", 1);
}

int		type_x(va_list ft_printf_list, t_flags *flag, char *base)
{
	uintmax_t	nb;
	int			size;

	ft_get_nb_u(ft_printf_list, &nb, flag);
	size = 0;
	ft_get_size_u((uintmax_t)nb, ft_strlen(base), &size);
	flag->width -= size;
	if (nb == 0)
		flag->hash = 0;
	if (flag->hash && nb != 0)
	{
		flag->total += 2;
		flag->width -= 2;
	}
	ft_display_x(nb, &size, flag, base);
	if (flag->prec <= 0)
		total_dit(nb, size, flag);
	flag->count += 1;
	return (flag->total);
}
