/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:34:38 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 13:35:24 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flags(t_flags *flag)
{
	flag->type = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->prec = -1;
	flag->neg = 0;
	flag->space = 0;
	flag->count = 0;
	flag->total = 0;
}

void	check_width(char **format, t_flags *flag)
{
	if (*(*format - 1) == '.')
	{
		flag->prec = ft_atoi(&(*(*format)));
		(*format) += (ft_getlen(flag->prec) - 1);
	}
	if (*(*format) != '0' && *(*format - 1) != '.' && flag->prec == -1)
	{
		flag->width = ft_atoi(&(*(*format)));
		(*format) += (ft_getlen(flag->width) - 1);
	}
}

void	check_flags(char **format, t_flags *flag)
{
	if (*(*format) == '*')
		flag->count = 1;
	if (*(*format) == ' ')
		flag->space = 1;
	if (*(*format) == '+')
		flag->plus = 1;
	if (*(*format) == '-')
		flag->minus = 1;
	if (*(*format) == '0' && *(*format - 1) != '.')
		flag->zero = 1;
	if (*(*format) == '#')
		flag->hash = 1;
	if (*(*format) == '.' && ft_isdigit((*(*format + 1))) == 0)
		flag->prec = -2;
	if ((ft_isdigit(*(*format))) == 1)
		check_width(&(*format), flag);
}

void	check_types(char **format, t_flags *flag)
{
	if (*(*format) == 'h' && *(*format - 1) != 'h')
		flag->type = TYPE_H;
	if (*(*format) == 'h' && *(*format + 1) == 'h')
		flag->type = TYPE_HH;
	if (*(*format) == 'l' && *(*format + 1) != 'l')
		flag->type = TYPE_L;
	if (*(*format) == 'l' && *(*format + 1) == 'l')
		flag->type = TYPE_LL;
	if (*(*format) == 'L')
		flag->type = TYPE_LF;
}

void	check_format(va_list ft_printf_list, char **format, t_flags *flag)
{
	if (*(*format) == '%')
		ft_print_percent(flag);
	else if (*(*format) == 's')
		type_s(ft_printf_list, flag);
	else if (*(*format) == 'c')
		type_c(ft_printf_list, flag);
	else if (*(*format) == 'd' || *(*format) == 'i')
		type_d(ft_printf_list, flag);
	else if (*(*format) == 'f')
		type_f(ft_printf_list, flag);
	else if (*(*format) == 'o')
		type_o(ft_printf_list, flag);
	else if (*(*format) == 'u')
		type_u(ft_printf_list, flag);
	else if (*(*format) == 'x')
		type_x(ft_printf_list, flag, "0123456789abcdef");
	else if (*(*format) == 'X')
		type_x(ft_printf_list, flag, "0123456789ABCDEF");
	else if (*(*format) == 'p')
		type_p(ft_printf_list, flag, "0123456789abcdef");
}
