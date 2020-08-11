/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_scp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrayne <rrayne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:46:57 by rrayne            #+#    #+#             */
/*   Updated: 2020/08/11 22:56:36 by rrayne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		type_s(va_list args, t_flags *flag)
{
	char		*s;
	int			width;
	size_t		len;

	width = 0;
	flag->total = 0;
	s = va_arg(args, char *);
	if (!s)
	{
		s = "(null)";
		len = 6;
	}
	total_str(s, &len, flag);
	if (flag->minus == 1 && (flag->zero = 1))
		ft_write(s, len);
	while (width++ < flag->width)
		ft_write((flag->zero == 0 ? "0" : " "), 1);
	if (!flag->minus)
		ft_write(s, len);
	flag->count += 1;
	return (flag->total);
}

int		type_c(va_list args, t_flags *flag)
{
	char	c;
	int		width;

	width = 0;
	c = va_arg(args, int);
	flag->total = 1;
	if (flag->minus == 1)
		ft_write(&c, 1);
	while (width < (flag->width - 1))
	{
		ft_write(" ", 1);
		width++;
	}
	if (!flag->minus)
		ft_write(&c, flag->total);
	flag->total += width;
	flag->count += 1;
	return (flag->total);
}

int		type_p(va_list args, t_flags *flag, char *base)
{
	unsigned long int	nb;
	int					size;

	nb = va_arg(args, unsigned long int);
	size = 0;
	flag->hash = 1;
	flag->type = P;
	ft_get_size_u((uintmax_t)nb, ft_strlen(base), &size);
	flag->width -= size;
	flag->width -= 2;
	if (flag->prec > 0 && nb == 0)
		flag->prec -= 1;
	ft_display_x(nb, &size, flag, base);
	if (flag->prec <= 0)
		total_dit(nb, size, flag);
	flag->total += 2;
	flag->count += 1;
	return (flag->total);
}
