/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:45:53 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 14:45:56 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_width(t_flags *flag)
{
	int		i;

	i = 0;
	while (i++ < flag->width)
	{
		if (flag->zero == 1 || flag->prec > 0)
			ft_write(" ", 1);
		else if (flag->zero == 0)
			ft_write("0", 1);
	}
}

void	ft_print_sign(t_flags *flag)
{
	if (flag->neg == 0)
	{
		if (flag->plus == 1)
			ft_write("+", 1);
		if (flag->space == 1)
			ft_write(" ", 1);
	}
	if (flag->neg == 1)
		ft_write("-", 1);
}

int		ft_print_percent(t_flags *flag)
{
	if (flag->width > 0)
		flag->width -= 1;
	if (flag->minus)
		flag->zero = 1;
	if (!flag->minus)
		ft_print_width(flag);
	ft_write("%", 1);
	flag->total = (flag->width > 0 ? flag->width + 1 : 1);
	if (flag->minus)
		ft_print_width(flag);
	flag->count += 1;
	return (flag->total);
}

int		ft_print_str(char **format)
{
	int		len;

	if (ft_strchr(*format, '%'))
		len = (int)(ft_strchr(*format, '%') - *format);
	else
		len = (int)(ft_strlen(*format));
	ft_write(*format, len);
	(*format) += len;
	return (len);
}
