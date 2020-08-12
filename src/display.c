/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:45:37 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/12 17:04:55 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_display_d(intmax_t nb, int size, t_flags *flag)
{
	if (check_zero((uintmax_t)nb, &size, flag) == -1)
		flag->count = 1;
	if (nb >= 0 && (flag->plus || flag->space) && flag->width > 0)
		flag->width--;
	ft_precision(flag, size);
	if (flag->zero)
		ft_print_sign(flag);
	if (!flag->minus && flag->width > 0)
		ft_print_width(flag);
	if (!flag->zero)
		ft_print_sign(flag);
	while (--flag->prec >= 0)
		ft_write("0", 1);
	if (size > 0 && flag->count != 1)
		ft_putnbr_base((uintmax_t)(nb < 0 ? -nb : nb), "0123456789", 10);
	if (flag->minus && flag->width > 0)
		ft_print_width(flag);
	total_dit((intmax_t)nb, size, flag);
}

void	ft_display_o(uintmax_t nb, int size, t_flags *flag)
{
	check_zero((uintmax_t)nb, &size, flag);
	if (nb > 0 && (flag->plus || flag->space))
		flag->width--;
	ft_precision(flag, size);
	if (flag->zero)
		ft_print_sign(flag);
	if (!flag->minus && flag->width > 0)
		ft_print_width(flag);
	if (!flag->zero)
		ft_print_sign(flag);
	if (flag->hash)
		ft_write("0", 1);
	while (flag->prec-- > 0)
		ft_write("0", 1);
	if (size > 0 && flag->count != 1)
		ft_putnbr_base((uintmax_t)nb, "01234567", 8);
	if (flag->minus && flag->width > 0)
		ft_print_width(flag);
	total_dit((intmax_t)nb, size, flag);
}

void	ft_display_u(uintmax_t nb, int size, t_flags *flag)
{
	if (check_zero((uintmax_t)nb, &size, flag) == -1)
		flag->count = 1;
	ft_precision(flag, size);
	if (!flag->minus && flag->width > 0)
		ft_print_width(flag);
	while (--flag->prec >= 0)
		ft_write("0", 1);
	if (size > 0 && flag->count != 1)
		ft_putnbr_base((uintmax_t)nb, "0123456789", 10);
	if (flag->minus && flag->width > 0)
		ft_print_width(flag);
	total_dit((intmax_t)nb, size, flag);
}
